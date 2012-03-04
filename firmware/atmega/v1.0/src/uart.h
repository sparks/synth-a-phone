/**
@file uart.h
@brief
*/

#ifndef SYNTH_UART
#define SYNTH_UART

#include <avr/io.h>

typedef void (*uart_callback_t)(void);

void uart_init(uart_callback_t);

void uart_tx(uint8_t);
void uart_string_tx(char* buf, uint8_t buf_len);

uint8_t uart_available(void);
uint8_t uart_rx(void);
void uart_string_rx(char* buf, uint8_t buf_len);

#endif