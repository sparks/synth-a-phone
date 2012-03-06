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

#include "adsr.h"
#include "osc.h"
#include "effects.h"

#include <avr/interrupt.h>
#include <util/delay.h>

void hf_sample(void);
void lf_sample(void);

volatile uint8_t too_slow_flag = 0;
volatile uint8_t compute_flag = 0;
int16_t hif_output = 0;
uint8_t env = 0;

int main(void) {

	adc_init();
	dac_init();
	timer_init(&hf_sample, &lf_sample);
	uart_init(&uart_callback);
	
	//init sine
	sine_init();
	uint24_t freq = {0,0,1};
	sei();

	for(;;) {
		if(compute_flag != 0) {
			hif_output = 0;
			// hif_output += ((triangle(100)>>4)*env)>>4;
			hif_output += (sine_uint24(freq));
			compute_flag = 0;
		}
	}
	
	return 0;
}

void hf_sample(void) {
	if(compute_flag == 0) {
		serial_dac(hif_output+2048);
		// par_dac(hif_output);
		compute_flag = 1;
	} else {
		too_slow_flag = 1;
	}
}

void lf_sample(void) {
	env = adsr_value();
	adc_trigger();
}
