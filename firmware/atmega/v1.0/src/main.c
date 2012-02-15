/**
@file main.c
@brief
*/

#include "main.h"

#include "adc.h"
#include "dac.h"
#include "synthesis.h"
#include "timer.h"
#include "wavetable.h"
#include "uart.h"
#include "filters.h"

#include <avr/interrupt.h>
#include <util/delay.h>

void trigger_computation(void);
void uart_rx(uint8_t);

volatile uint8_t too_slow_flag = 0;
volatile uint8_t compute_flag = 0;
uint16_t hif_output = 0;


int main(void) {
	uint8_t filter_idx = 0;

	adc_init();
	dac_init();
	timer_init(&trigger_computation, 0x50);
	uart_init(&uart_rx);
	
	sei();

	for(;;) {
		uart_string_tx("Hello\n", 6);
		_delay_ms(1000);
	}

	for(;;) {
		if(compute_flag != 0) {
			hif_output = 0;
			hif_output += sawtooth(((adc_val(1) >> 3)+1)*triangle((adc_val(0) >> 4)));
			
			x_n[filter_idx] = hif_output;
			filter_idx++;
			if(filter_idx >= FILTER_1_ORDER) filter_idx = filter_idx%FILTER_1_ORDER;
			
			low_pass(&y_n[filter_idx]);
	
			compute_flag = 0;
		}
	}
	
	return 0;
}

void uart_rx(uint8_t val) {
	return;
}

void trigger_computation(void) {
	if(compute_flag != 0) {
		too_slow_flag = 1;
	} else {
		if(!is_lossy() && too_slow_flag == 0) {
			serial_dac(hif_output);
			compute_flag = 1;
		}
	}
}
