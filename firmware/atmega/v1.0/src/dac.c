/**
@file dac.c
@brief
*/

#include "dac.h"

#include "main.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#define SERIAL_DAC_SCK PB5
#define SERIAL_DAC_DIN PB3
#define SERIAL_DAC_CS PB2
#define SERIAL_DAC_LDAC PB1

#define SERIAL_DAC_CONF 0x30

#define PAR_DAC_WR PD2
#define PAR_DAC_AB PD3
#define PAR_DAC_NIBBLE_LOW PC0
#define PAR_DAC_NIBBLE_HIGH PD4

typedef enum {
	IDLE,
	FIRST_BYTE,
	SECOND_BYTE
} dac_state_t;

dac_state_t ser_dac_state = IDLE;
dac_state_t par_dac_state = IDLE;

uint8_t data[2];

uint8_t lossy_flag = 0;

void dac_init(void) {
	DDRB |= (1 << SERIAL_DAC_LDAC) | (1 << SERIAL_DAC_DIN) | (1 << SERIAL_DAC_CS) | (1 << SERIAL_DAC_SCK);
	PORTB |= (1 << SERIAL_DAC_LDAC) | (0 << SERIAL_DAC_DIN) | (1 << SERIAL_DAC_CS) | (0 << SERIAL_DAC_SCK);

	DDRC |= (0x0F << PAR_DAC_NIBBLE_LOW);
	PORTC &= ~(0x0F << PAR_DAC_NIBBLE_LOW);

	DDRD |= (1 << PAR_DAC_WR) | (1 << PAR_DAC_AB) | (0x0F << PAR_DAC_NIBBLE_HIGH);
	PORTD &= ~((1 << PAR_DAC_WR) | (1 << PAR_DAC_AB) | (0x0F << PAR_DAC_NIBBLE_HIGH));

	SPCR = (1 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR = (1 << SPI2X);
}

void par_dac(uint16_t value) {
	if(par_dac_state == IDLE) {
		par_dac_state = FIRST_BYTE;

		PORTD &= ~(1 << PAR_DAC_WR); //Low write
		PORTD &= ~(1 << PAR_DAC_AB); //low ab

		PORTC &= ~(0x0F << PAR_DAC_NIBBLE_LOW);
		PORTD &= ~(0x0F << PAR_DAC_NIBBLE_HIGH);

		PORTC |= ((value & 0x0F) << PAR_DAC_NIBBLE_LOW);
		PORTD |= (((value >> 4) & 0x0F) << PAR_DAC_NIBBLE_HIGH);

		PORTD |= (1 << PAR_DAC_WR); //high write

		par_dac_state = SECOND_BYTE;

		PORTD &= ~(1 << PAR_DAC_WR); //Low write
		PORTD |= (1 << PAR_DAC_AB); //high ab

		PORTC &= ~(0x0F << PAR_DAC_NIBBLE_LOW);
		PORTD &= ~(0x0F << PAR_DAC_NIBBLE_HIGH);

		PORTC |= (((value >> 8) & 0x0F) << PAR_DAC_NIBBLE_LOW);
		PORTD |= (((value >> 12) & 0x0F) << PAR_DAC_NIBBLE_HIGH);

		PORTD |= (1 << PAR_DAC_WR); //high write

		par_dac_state = IDLE;
	} else {
		lossy_flag = 1;
	}
}

void serial_dac(uint16_t value) {
	if(ser_dac_state == IDLE) {
		data[0] = SERIAL_DAC_CONF | (value & 0xF00) >> 8;
		data[1] = value & 0xFF;

		PORTB &= ~(1 << SERIAL_DAC_CS); //CS low

		ser_dac_state = FIRST_BYTE;

		SPDR = data[0];
	} else {
		lossy_flag = 1; //Too fast
	}
}

uint8_t is_idle(void) {
	if(ser_dac_state == IDLE && par_dac_state == IDLE) return 1;
	else return 0;
}

uint8_t is_lossy(void) {
	return lossy_flag;
}

ISR(SPI_STC_vect) {
	if(ser_dac_state == FIRST_BYTE) {
		ser_dac_state = SECOND_BYTE;

		SPDR = data[1];
	} else if(ser_dac_state == SECOND_BYTE) {
		PORTB |= (1 << SERIAL_DAC_CS); //CS high

		PORTB &= ~(1 << SERIAL_DAC_LDAC); //LDAC low
		_delay_us(1); //min LDAC pulse width
		PORTB |= (1 << SERIAL_DAC_LDAC); //LDAC high

		ser_dac_state = IDLE;
	}
}

