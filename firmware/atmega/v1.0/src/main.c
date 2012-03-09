/**
\file main.c
\brief
*/

#include "main.h"

#include "adc.h"
#include "dac.h"
#include "timer.h"
#include "uart.h"
#include "midi.h"

#include "adsr.h"
#include "osc.h"
#include "effects.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#define USING_KEYS 0 // Using an actual keyboard?

void hf_sample(void);
void lf_sample(void);

volatile uint8_t too_slow_flag = 0;
volatile uint8_t compute_flag = 0;
int16_t hif_output = 0;
uint8_t env = 0;
uint8_t freq[3] = {0, 0, 1};

int main(void) {

	adc_init();
	dac_init();
	timer_init(&hf_sample, &lf_sample);
	uart_init(&uart_callback);
	
	//init sine
	sine_init();
	sei();

	for(;;) {
		if(compute_flag != 0) {
			hif_output = 0;
			
			if (USING_KEYS) {
			
				if(adc_val(1) < 350) {
					hif_output += ((sine_uint24(freq)>>4)*env)>>4;
				} else if(adc_val(1) < 700) {
					hif_output += ((sawtooth(freq[2])>>4)*env)>>4;
				} else {
					hif_output += ((triangle(freq[2])>>4)*env)>>4;
				}
				
			} else {
				
				// Stacked wave.
				hif_output += sine_uint24(freq)>>1;
				hif_output += triangle(freq[2]<<2)>>1;
			
				if (adc_val(0) > 512) {
					clip(&hif_output);
				}
			}
			
			compute_flag = 0;
		}
	}
	
	return 0;
}

void hf_sample(void) {
	if(compute_flag == 0) {
		// if(!too_slow_flag) {
			serial_dac(hif_output+2048);
			// par_dac(hif_output);
			compute_flag = 1;
		// }
	} else {
		too_slow_flag = 1;
	}
}

void lf_sample(void) {
	env = adsr_value();
	
	if (USING_KEYS) {
	
		get_delta(freq);
		uint8_t detune[3];
		detune[0] = adc_val(0) >> 2;
		detune[1] = adc_val(2) >> 2;
		detune[2] = 0;
		
		asm volatile(	"add %0, %3" "\n\t"
				"adc %1, %4" "\n\t"
				"adc %2, %5" "\n\t" :
			"+r" (freq[0]), "+r" (freq[1]), "+r" (freq[2]),
			"+r" (detune[0]), "+r" (detune[1]), "+r" (detune[2]));
			
	} else {
	
		freq[0] = 0; //adc_val(0) >> 2;
		freq[1] = adc_val(2) >> 2;
		freq[2] = adc_val(1) >> 2;	
	}	
		
	adc_trigger();
}
