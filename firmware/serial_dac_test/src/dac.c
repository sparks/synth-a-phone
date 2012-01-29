#include "dac.h"

#include "main.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#define SERIAL_DAC_SCK PB5
#define SERIAL_DAC_DIN PB3
#define SERIAL_DAC_CS PB2
#define SERIAL_DAC_LDAC PB1

#define SERIAL_DAC_CONF 0x30

enum state {
	IDLE,
	FIRST_BYTE,
	SECOND_BYTE
} state = IDLE;

uint8_t data[2];

uint8_t lossy_flag = 0;

void dac_init(void) {
	DDRB |= (1 << SERIAL_DAC_LDAC) | (1 << SERIAL_DAC_DIN) | (1 << SERIAL_DAC_CS) | (1 << SERIAL_DAC_SCK);
	PORTB |= (1 << SERIAL_DAC_LDAC) | (0 << SERIAL_DAC_DIN) | (1 << SERIAL_DAC_CS) | (0 << SERIAL_DAC_SCK);

	SPCR = (1 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR = (1 << SPI2X);
}

void serial_dac_blocking(uint16_t value) {
	PORTB &= ~(1 << SERIAL_DAC_CS); //CS low

	data[0] = SERIAL_DAC_CONF | (value & 0xF00) >> 8; //Top 4 bits
	data[1] = value & 0xFF; //Bottom 8 bits

	SPDR = data[0]; //First send conf+top 4bits
	while((SPSR & (1 << SPIF)) == 0); //Wait for send

	SPDR = data[1]; //Next send bottom 8 bits
	while((SPSR & (1 << SPIF)) == 0); //Wait for send

	PORTB |= (1 << SERIAL_DAC_CS); //CS high

	//Latch
	PORTB &= ~(1 << SERIAL_DAC_LDAC); //LDAC low
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << SERIAL_DAC_LDAC); //LDAC high
}

void serial_dac(uint16_t value) {
	if(state == IDLE) {
		data[0] = SERIAL_DAC_CONF | (value & 0xF00) >> 8;
		data[1] = value & 0xFF;

		PORTB &= ~(1 << SERIAL_DAC_CS); //CS low

		state = FIRST_BYTE;

		SPDR = data[0];
	} else {
		lossy_flag = 1; //Too fast
	}
}

uint8_t is_idle(void) {
	if(state == IDLE) return 1;
	else return 0;
}

uint8_t is_lossy(void) {
	return lossy_flag;
}

ISR(SPI_STC_vect) {
	if(state == FIRST_BYTE) {
		state = SECOND_BYTE;

		SPDR = data[1];
	} else if(state == SECOND_BYTE) {
		PORTB |= (1 << SERIAL_DAC_CS); //CS high

		PORTB &= ~(1 << SERIAL_DAC_LDAC); //LDAC low
		_delay_us(1); //min LDAC pulse width
		PORTB |= (1 << SERIAL_DAC_LDAC); //LDAC high

		state = IDLE;
	}
}