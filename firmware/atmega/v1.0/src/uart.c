/**
@file uart.c
@brief
*/

#include "uart.h"

#include <avr/interrupt.h>

/**
 * The UART baud rate to transmit at.
*/
#define BAUD_RATE 31250 //Midi rate
// #define BAUD_RATE 115200
#define UBRR ((F_CPU+BAUD_RATE*4L)/(BAUD_RATE*8L)-1)
/**
 * The length of the send and receive buffers to be allocated for UART communication.
*/
#define BUF_LEN 16

uart_callback_t uart_callback;

uint8_t in_head, in_tail = 0;
uint8_t in_buf[BUF_LEN];

uint8_t out_head, out_tail = 0;
uint8_t out_buf[BUF_LEN];

void uart_init(uart_callback_t c) {
	uart_callback = c;
	UCSR0A |= (1 << U2X0);
	UCSR0B |= (1 << RXCIE0) | (1 << TXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	UBRR0L = UBRR >> 8;
	UBRR0L = UBRR;
}

void uart_tx(uint8_t val) {
	uint8_t next_tail = (out_tail+1)%BUF_LEN; //Next tail position

	if(next_tail != out_head) { //If there is space in the buffer
		out_buf[out_tail] = val; //Add to the buffer

		if(out_tail == out_head) { //If the buffer was empty
			out_tail = next_tail; //Increment the tail
			UDR0 = out_buf[out_head]; //And start sending
		} else {
			out_tail = next_tail; //Increment the tail, we're already sending
		}
	}	
}

void uart_string_tx(uint8_t* buf, uint8_t buf_len) {
	uint8_t empty = 0;
	if(out_head == out_tail) empty = 1; //Check if the buf is empty when we start

	uint8_t i; //Precompute next tail

	for(i = 0;i < buf_len;i++) { //Foreach
		uint8_t next_tail = (out_tail+1)%BUF_LEN; //Precompute nextail
		if(next_tail == out_head) break; //Leave if the buffer is full

		out_buf[out_tail] = *(buf+i); //Add to the buffer
		out_tail = next_tail; //Increment tail		
	}

	if(empty) UDR0 = out_buf[out_head];
}

uint8_t uart_rx(void) {	
	uint8_t value = 0;

	if(in_head != in_tail) {
		value = in_buf[in_head];
		in_head = (in_head+1)%BUF_LEN;
	}

	return value;
}

uint8_t uart_available(void) {
	int8_t available = in_tail;
	if(available < in_head) available += BUF_LEN;
	available -= in_head;
	return available;
}

void uart_string_rx(uint8_t* buf, uint8_t buf_len) {
	uint8_t i; //Precompute next tail

	for(i = 0;i < buf_len;i++) { //Foreach
		if(in_head == in_tail) break; //Leave if the buffer is empty

		*(buf+i) = in_buf[in_head]; //Copy value into the buffer
		in_head = (in_head+1)%BUF_LEN; //Increment head 
	}
}

ISR(USART_RX_vect) {
	in_buf[in_tail] = UDR0; //Grab new value
	in_tail = (in_tail+1)%BUF_LEN; //Update tail
	if(in_tail == in_head) in_head = (in_head+1)%BUF_LEN; //Drop old values if buffer is full
	(*uart_callback)(); //Callback
}

ISR(USART_TX_vect) {
	out_head = (out_head+1)%BUF_LEN; //Increment the head
	if(out_head != out_tail) UDR0 = out_buf[out_head]; //Keep sending
}