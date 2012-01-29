#include "main.h"

#include "adc.h"
#include "dac.h"
#include "synthesis.h"
#include "timer.h"

#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t compute_flag = 0;
uint8_t slow_flag = 0;

int main(void) {
	adc_init();
	dac_init();
	timer_init();

	sei();

	for(;;) {
		if(compute_flag) {
			sawtooth((adc_val(0) >> 2) + 1);

			compute_flag = 0;
		}
	}
	
	return 0;
}

void trigger_computation(void) {
	if(compute_flag) slow_flag = 1;
	compute_flag = 1;
}