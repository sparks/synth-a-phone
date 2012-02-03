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

#include <avr/interrupt.h>
#include <util/delay.h>

void trigger_computation(void);
void uart_rx(uint8_t);

volatile uint8_t too_slow_flag = 0;
volatile uint8_t compute_flag = 0;
uint16_t output = 0;

int main(void) {
	adc_init();
	dac_init();
	timer_init(&trigger_computation, 0x50);
	uart_init(&uart_rx);

	sei();

	sine_init();

/*	for(;;) {
		if(compute_flag != 0) {
			output = 0;
			output += sine((adc_val(0) >> 3) + 1);
			compute_flag = 0;
		}
	}*/

	for(;;) {
		uart_tx(0x9F);
		uart_tx(0x3C);
		uart_tx(0x7F);
		_delay_ms(1000);

		uart_tx(0x8F);
		uart_tx(0x3C);
		uart_tx(0x00);
		_delay_ms(1000);

		uart_tx(0x9F);
		uart_tx(0x3D);
		uart_tx(0x7F);
		_delay_ms(1000);

		uart_tx(0x8F);
		uart_tx(0x3D);
		uart_tx(0x00);
		_delay_ms(1000);

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
		//if(!is_lossy() && too_slow_flag == 0) {
			serial_dac(output);
			compute_flag = 1;
		//}
	}
}

