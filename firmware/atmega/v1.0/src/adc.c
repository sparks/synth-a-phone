/**
\file adc.c
\brief Provide a mechanism to easily get ADC (PORTC) values with externally controlled sampling rate.
*/

#include "adc.h"

#include <avr/interrupt.h>

/** The first pin on PORTC to perform ADC conversion on. */
#define ADC_MUX_MIN 4
/** The last pin on PORTC to perfrom ADC conversion on. */
#define ADC_MUX_MAX 7
/** The number of pins on PORTC to perform ADC conversion on. */
#define ADC_MUX_LEN ADC_MUX_MAX-ADC_MUX_MIN

uint8_t mux_pointer = ADC_MUX_MIN;
uint16_t latest_values[ADC_MUX_LEN];

void adc_init(void) {
	uint8_t i;
	for(i = 0;i < ADC_MUX_LEN;i++) {
		DDRC &= ~(1 << (i+ADC_MUX_MIN));
		latest_values[i] = 0;
	}

	ADMUX = (1 << REFS0) | (0 << ADLAR) | mux_pointer;
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	adc_trigger();
}

void adc_trigger(void) {
	if(mux_pointer == ADC_MUX_MIN) ADCSRA |= (1 << ADSC); //Trigger first sequence if not already running a cycle
}

uint16_t adc_val(uint8_t mux) {
	if(mux < ADC_MUX_LEN) return latest_values[mux];
	else return ADC_ERROR_CODE;
}

/**
 * Handle the ADC conversion complete interrupt. Get the ADC value and store it, then check if another adc conversion should be initated.
 *
*/
ISR(ADC_vect) {
	latest_values[mux_pointer-ADC_MUX_MIN] = ADCL;
	latest_values[mux_pointer-ADC_MUX_MIN] |= ADCH << 8;

	if(++mux_pointer >= ADC_MUX_MAX) mux_pointer = ADC_MUX_MIN;

	ADMUX &= ~(0x0F);
	ADMUX |= mux_pointer;

	if(mux_pointer != ADC_MUX_MIN) ADCSRA |= (1 << ADSC); //Keep triggering through all ADC channels (ALWAYS LAST IN INTERRUPT)
}

