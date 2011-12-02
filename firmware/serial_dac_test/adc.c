#include "adc.h"

#include <avr/interrupt.h>

#define MUX_MIN 4
#define MUX_MAX 7
#define MUX_LEN MUX_MAX-MUX_MIN

uint8_t mux_pointer = MUX_MIN;
uint16_t latest_values[MUX_LEN];

void adc_init(void) {
	uint8_t i;
	for(i = 0;i < MUX_LEN;i++) {
		DDRC &= ~(1 << (i+MUX_MIN));
		latest_values[i] = 0;
	}

	ADMUX = (1 << REFS0) | (0 << ADLAR) | mux_pointer;
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	ADCSRA |= (1 << ADSC); //Trigger first sequence
}

uint16_t adc_val(uint8_t mux) {
	if(mux < MUX_LEN) return latest_values[mux];
	else return ADC_ERROR;
}

ISR(ADC_vect) {
	latest_values[mux_pointer-MUX_MIN] = ADCL;
	latest_values[mux_pointer-MUX_MIN] |= ADCH << 8;

	if(mux_pointer+1 < MUX_MAX) mux_pointer++;
	else mux_pointer = MUX_MIN;

	ADMUX &= ~(0xF);
	ADMUX |= mux_pointer;


	ADCSRA |= (1 << ADSC); //Trigger sequence
}