/**
@file uart.h
@brief Provide simple lightweight access to send and recieve single bytes or short strings via UART.
*/

#ifndef SYNTH_UART
#define SYNTH_UART

#include <avr/io.h>

typedef void (*uart_callback_t)(void);

/**
 * Configures the UART baudrate and interrupts. Registers an RX callback, which triggers every time a new byte is received.
 *
 * @param c the RX callback to be registered.
*/
void uart_init(uart_callback_t c);

/**
 * Places a single byte in the TX buffer to be transmitted over UART. The TX buffer is FIFO. If the TX buffer is full the byte will be dropped.
 *
 * @param val the byte to transmitted.
*/
void uart_tx(uint8_t val);
/**
 * Places a string (or array of bytes) of given length in the TX buffer to be transmitted over UART. The TX buffer is FIFO. If the length of the string exceeds the free space in the TX buffer it will be truncated.
 *
 * @param buf a pointer to the string or array of bytes.
 * @param buf_len the length of the string or array.
*/
void uart_string_tx(uint8_t* buf, uint8_t buf_len);

/**
 * Gives the number of bytes received which are available to be read in the buffer.
 *
 * @return the number of bytes available to be read.
*/
uint8_t uart_available(void);
/**
 * Gets a single byte from the RX buffer. The RX buffer is FIFO. If the buffer is empty zero will be returned.
 *
 * @return the oldest byte in the RX buffer or zero if the buffer is empty.
*/
uint8_t uart_rx(void);
/**
 * Overwrites a given string or array of bytes with values from the RX buffer. The RX buffer if FIFO. If there are not enough values in the RX buffer, the array will be only partially overwritten.
 *
 * @param buf the string or array of bytes to be overwritten.
 * @param buf_len the length of the string of array.
*/
void uart_string_rx(uint8_t* buf, uint8_t buf_len);

#endif
