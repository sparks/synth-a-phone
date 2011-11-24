#include "adc.h"

#include <avr/interrupt.h>

#define ADC4_MUX 0x04
#define ADC5_MUX 0x05
#define ADC6_MUX 0x06

uint16_t input12;
uint8_t input8;

void adc_init(void) {
	DDRC &= ~((1 << PC4) | (1 << PC5) | (1 << PC6));

	ADMUX = (1 << REFS0) | (0 << ADLAR) | ADC5_MUX;
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	sei();  //enable global interrupt
	ADCSRA |= (1 << ADSC); //Trigger first sequence
}

uint8_t get_val8(void) {
	return input8;
}

uint16_t get_val12(void) {
	return input12;
}

ISR(ADC_vect) {
	input12 = ADCL;
	input12 |= ADCH << 8;
	input8 = input12 >> 2;
	ADCSRA |= (1 << ADSC); //Trigger first sequence
}