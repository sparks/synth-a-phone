/**
@file uart.c
@brief
*/

#include "uart.h"

#include <avr/interrupt.h>

#define BAUD_RATE 115200
#define UBRR ((F_CPU/8/BAUD_RATE)- 1)

uart_state_t uart_state = IDLE;

uart_callback_t uart_callback;

void uart_init(uart_callback_t c) {
	uart_callback = c;
	UCSR0A |= (1 << U2X0);
	UCSR0B |= (0 << RXCIE0) | (0 << TXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UBRR0L = UBRR >> 8;
	UBRR0L = UBRR;
}

void uart_tx(uint8_t val) {
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = val;
	uart_state = TX;
}

void uart_string_tx(char* buf, uint8_t buf_len) {
	uint8_t i;
	for(i = 0;i < buf_len;i++) {
		uart_tx(*(buf+i));
	}
	return;
}

uart_state_t get_state(void) {
	return uart_state;
}

ISR(USART_RX_vect) {
	(*uart_callback)(UDR0);
	uart_state = IDLE;
}

ISR(USART_TX_vect) {
	uart_state = IDLE;
}