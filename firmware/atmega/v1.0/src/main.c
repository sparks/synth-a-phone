/**
@file main.c
@brief
*/

#include "main.h"

#include "adc.h"
#include "dac.h"
#include "timer.h"
#include "uart.h"
#include "midi.h"

#include "osc.h"
#include "effects.h"

#include <avr/interrupt.h>
#include <util/delay.h>

void hf_sample(void);
void lf_sample(void);

volatile uint8_t too_slow_flag = 0;
volatile uint8_t compute_flag = 0;
uint16_t hif_output = 0;


int main(void) {
	uint8_t filter_idx = 0;

	adc_init();
	dac_init();
	timer_init(&hf_sample, &lf_sample);
	uart_init(&uart_callback);
	
	sei();

	for(;;) {
		if(compute_flag != 0) {
			hif_output = 0;
			
			if (adc_val(2) > 511)
				hif_output += sawtooth((adc_val(0) >> 3) + 1);
			else
				hif_output += triangle((adc_val(0) >> 3) + 1);
			
			/*
			x_n[filter_idx] = hif_output;
			filter_idx++;
			if(filter_idx >= FILTER_1_ORDER) filter_idx = filter_idx%FILTER_1_ORDER;
			
			low_pass(&y_n[filter_idx]);
			*/
			
			if (adc_val(1) > 511)
				clip(&hif_output);
				
			compute_flag = 0;
		}
	}
	
	return 0;
}

void hf_sample(void) {
	if(compute_flag == 0) {
		serial_dac(hif_output);
		// par_dac(hif_output);
		compute_flag = 1;
	} else {
		too_slow_flag = 1;
	}
}

void lf_sample(void) {
	adc_trigger();
}
