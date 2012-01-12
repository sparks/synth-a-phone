#include "dac.h"

#include <util/delay.h>

void dac_init(void) {
	DDRB |= (1 << DAC_LDAC) | (1 << DAC_DIN) | (1 << DAC_CS) | (1 << DAC_SCK);
	PORTB |= (1 << DAC_LDAC) | (0 << DAC_DIN) | (1 << DAC_CS) | (0 << DAC_SCK);

	SPCR = (0 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR = (1 << SPI2X);
}

void dac8(uint8_t data) {
	PORTB &= ~(1 << DAC_CS); //CS low

	SPDR = DAC_CONF | (data & 0xF0) >> 4;
	while((SPSR & (1 << SPIF)) == 0);

	SPDR = (data & 0x0F) << 4;
	while((SPSR & (1 << SPIF)) == 0);

	PORTB |= (1 << DAC_CS); //CS high

	PORTB &= ~(1 << DAC_LDAC); //LDAC low
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << DAC_LDAC); //LDAC high
}

void dac12(uint16_t data) {
	PORTB &= ~(1 << DAC_CS); //CS low

	SPDR = DAC_CONF | (data & 0xF00) >> 8;
	while((SPSR & (1 << SPIF)) == 0);

	SPDR = (data & 0xFF);
	while((SPSR & (1 << SPIF)) == 0);

	PORTB |= (1 << DAC_CS); //CS high

	PORTB &= ~(1 << DAC_LDAC); //LDAC low
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << DAC_LDAC); //LDAC high
}

void dac_split(uint8_t data1, uint8_t data2) {
	PORTB &= ~(1 << DAC_CS); //CS low

	SPDR = DAC_CONF | (data1 & 0x0F);
	while((SPSR & (1 << SPIF)) == 0);

	SPDR = (data2 & 0xFF);
	while((SPSR & (1 << SPIF)) == 0);

	PORTB |= (1 << DAC_CS); //CS high

	PORTB &= ~(1 << DAC_LDAC); //LDAC low
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << DAC_LDAC); //LDAC high
}