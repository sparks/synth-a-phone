/**
@file uart.h
@brief
*/

#ifndef SYNTH_UART
#define SYNTH_UART

#include <avr/io.h>

typedef void (*uart_callback)(uint8_t);

typedef enum {
	IDLE,
	TX,
	RX
} uart_state_t;

void uart_init(uart_callback);

void uart_tx(uint8_t);

uart_state_t get_state(void);

#endif