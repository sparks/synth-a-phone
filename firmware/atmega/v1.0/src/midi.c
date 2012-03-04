/**
@file midi.c
@brief
*/

#include "uart.h"

void uart_callback(void) {
	if(uart_available() >= 3) {
		uint8_t str[3];
		uart_string_rx(str, 3);
		uart_string_tx(str, 3);
	}

	return;
}

// for(;;) {
// 	uart_tx(0x9F);
// 	uart_tx(0x3C);
// 	uart_tx(0x7F);
// 	_delay_ms(1000);

// 	uart_tx(0x8F);
// 	uart_tx(0x3C);
// 	uart_tx(0x00);
// 	_delay_ms(1000);

// 	uart_tx(0x9F);
// 	uart_tx(0x3D);
// 	uart_tx(0x7F);
// 	_delay_ms(1000);

// 	uart_tx(0x8F);
// 	uart_tx(0x3D);
// 	uart_tx(0x00);
// 	_delay_ms(1000);
// }