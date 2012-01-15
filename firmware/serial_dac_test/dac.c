#include "dac.h"

#include <util/delay.h>
#include <avr/interrupt.h>

enum state {
	IDLE,
	FIRST_BYTE,
	SECOND_BYTE
};

enum state current_state = IDLE;

uint8_t buffer_flag = 0;

uint8_t data[2];
uint8_t buffer[2];

void dac_init(void) {
	DDRB |= (1 << DAC_LDAC) | (1 << DAC_DIN) | (1 << DAC_CS) | (1 << DAC_SCK);
	PORTB |= (1 << DAC_LDAC) | (0 << DAC_DIN) | (1 << DAC_CS) | (0 << DAC_SCK);

	SPCR = (1 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR = (1 << SPI2X);
}

void serial_dac(uint16_t value) {
	// PORTB &= ~(1 << DAC_CS); //CS low

	// data[0] = value & 0xFF;
	// data[1] = (value & 0xF00) >> 8;

	// SPDR = DAC_CONF | data[1];
	// while((SPSR & (1 << SPIF)) == 0);

	// SPDR = data[0];
	// while((SPSR & (1 << SPIF)) == 0);
	
	// PORTB |= (1 << DAC_CS); //CS high

	// PORTB &= ~(1 << DAC_LDAC); //LDAC low
	// _delay_us(1); //min LDAC pulse width
	// PORTB |= (1 << DAC_LDAC); //LDAC high

	if(current_state == IDLE) {
		current_state = FIRST_BYTE;
		
		PORTB &= ~(1 << DAC_CS); //CS low

		data[0] = value & 0xFF;
		data[1] = (value & 0xF00) >> 8;

		current_state = FIRST_BYTE;

		SPDR = DAC_CONF | data[1];
	} else {
		buffer_flag = 1;

		buffer[0] = value & 0xFF;
		buffer[1] = (value & 0xF00) >> 8;
	}
}

ISR(SPI_STC_vect) {
	cli();

	if(current_state == FIRST_BYTE) {
		SPDR = data[0];

		current_state = SECOND_BYTE;

	} else if(current_state == SECOND_BYTE) {
		PORTB |= (1 << DAC_CS); //CS high

		PORTB &= ~(1 << DAC_LDAC); //LDAC low
		_delay_us(1); //min LDAC pulse width
		PORTB |= (1 << DAC_LDAC); //LDAC high

		if(buffer_flag) {
			current_state = FIRST_BYTE;
		
			buffer_flag = 0;

			PORTB &= ~(1 << DAC_CS); //CS low

			data[0] = buffer[0];
			data[1] = buffer[1];

			current_state = FIRST_BYTE;

			SPDR = DAC_CONF | data[1];
		} else {
			current_state = IDLE;
		}

	}

	sei();
}