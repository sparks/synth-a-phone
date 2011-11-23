#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

#define DAC_SCK PB5
#define DAC_DIN PB3
#define DAC_CS PB2
#define DAC_LDAC PB1

void dac(uint8_t data);
void dac2(uint8_t data1, uint8_t data2);

#define PERIOD 200

uint8_t sintable[PERIOD];

int main() {
	DDRB |= (1 << DAC_LDAC) | (1 << DAC_DIN) | (1 << DAC_CS) | (1 << DAC_SCK);
	PORTB |= (1 << DAC_LDAC) | (0 << DAC_DIN) | (1 << DAC_CS) | (0 << DAC_SCK);
	
	SPCR = (0 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR = (1 << SPI2X);
	
	uint8_t i;

	for(i = 0;i < PERIOD;i++) {
		sintable[i] = 0xFF & (uint8_t)round((sin(M_PI*2/PERIOD*i)+1)*0x7F);
	}
	
	uint32_t t;

	for(t = 0;;t++) {
		dac(((t*7&t>>3)|(~t*t)&t>>9)&t*3>>13); // mimi ami forme d'art
		_delay_us(100);
	}

	for(;;) {
		for(i = 0;i < 0xFF;i++) {
			dac(i);
		}
	}

	for(;;) {
		for(i = 0;i < PERIOD;i++) {
			dac(sintable[i]);
			_delay_us(2);
		}
	}
	
	return 0;

}

void dac(uint8_t data) {
	uint8_t control = 0x03;
	
	PORTB &= ~(1 << DAC_CS); //CS low

	SPDR = (control & 0x0F) << 4 | (data & 0xF0) >> 4; 
	// _delay_us(1);
	while((SPSR & (1 << SPIF)) == 0);
	
	SPDR = (data & 0x0F) << 4;
	// _delay_us(1);
	while((SPSR & (1 << SPIF)) == 0);
	
	PORTB |= (1 << DAC_CS);
	
	PORTB &= ~(1 << DAC_LDAC);
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << DAC_LDAC);	
	
}

void dac2(uint8_t data1, uint8_t data2) {
	uint8_t control = 0x03;
	
	PORTB &= ~(1 << DAC_CS); //CS low

	SPDR = (control & 0x0F) << 4 | (0x0F & data1); 
	// _delay_us(1);
	while((SPSR & (1 << SPIF)) == 0);
	
	SPDR = data2;
	// _delay_us(1);
	while((SPSR & (1 << SPIF)) == 0);
	
	PORTB |= (1 << DAC_CS);
	
	PORTB &= ~(1 << DAC_LDAC);
	_delay_us(1); //min LDAC pulse width
	PORTB |= (1 << DAC_LDAC);	
	
}