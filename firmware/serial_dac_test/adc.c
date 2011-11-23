#include "adc.h"

#include <avr/interrupt.h>

#define ADC4_MUX 0x04
#define ADC5_MUX 0x05
#define ADC6_MUX 0x06

uint8_t input;

void adc_init(void) {
	ADMUX = (1 << REFS1) | (1 << ADLAR) | ADC5_MUX;
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS1) | (1 << ADPS0);

	sei();  //enable global interrupt
	ADCSRA |= (1 << ADSC); //Trigger first sequence

}

uint8_t get_val(void) {
	return input;
}

ISR(ADC_vect) {
	input = ADCH;
	ADCSRA |= (1 << ADSC);
}