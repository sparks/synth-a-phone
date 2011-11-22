#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DAC_SCK PB5
#define DAC_CS PB2
#define DAC_DIN PB3
#define DAC_LDAC PB1

void dac(char data);

int main() {
	DDRB |= (1 << DAC_LDAC) | (1 << DAC_DIN) | (1 << DAC_CS) | (1 << DAC_SCK);
	PORTB |= (1 << DAC_LDAC) | (0 << DAC_DIN) | (1 << DAC_CS) | (0 << DAC_SCK);
	
	SPCR = (0 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
	SPSR &= ~(1 << SPI2X);
	
	for(;;) {
		char i;
		for(i = 0;i < 250;i++) {
			dac(i);
			// _delay_ms(1);
		}
	}
	
	return 0;

}

void dac(char data) {
	char control = 0x05;
	
	PORTB |= (1 << DAC_LDAC);
	PORTB &= ~(1 << DAC_CS);

	SPDR = (control & 0x0F) << 4 | (data & 0xF0) >> 4;
	_delay_us(1);
	// while((SPSR & SPIF) == 0);
	
	SPDR = (data & 0x0F) << 4;
	_delay_us(1);
	// while((SPSR & SPIF) == 0);
	
	PORTB |= (1 << DAC_CS);
	
	PORTB &= ~(1 << DAC_LDAC);
	
	
}