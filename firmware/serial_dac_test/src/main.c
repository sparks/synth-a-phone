/**
@file main.c
@brief
*/

#include "main.h"

#include "adc.h"
#include "dac.h"
#include "synthesis.h"
#include "timer.h"

#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t compute_flag = 0;
uint16_t output = 0;

int main(void) {
	adc_init();
	dac_init();
	timer_init(&trigger_computation, 0x26);

	sei();

	for(;;) {
		if(compute_flag != 0) {
			// output = sawtooth((adc_val(0) >> 2) + 1);
			output = triangle((adc_val(0) >> 2) + 1);
			compute_flag = 0;
		}
	}
	
	return 0;
}

void trigger_computation(void) {
	// serial_dac(output);
	if(!is_lossy()) serial_dac(output);
	compute_flag = 1;
}