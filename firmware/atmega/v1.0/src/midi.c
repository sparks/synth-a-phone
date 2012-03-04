/**
@file midi.c
@brief
*/

#include "midi.h"
#include "uart.h"

uint8_t pitch = 100;
uint8_t velocity = 0;
uint8_t midi_msg[3];

void uart_callback(void) {
	if(uart_available() >= 3) {
		midi_msg[0] = uart_rx();
		if((midi_msg[0] & 0x80) == 0) return;
		midi_msg[1] = uart_rx();
		midi_msg[2] = uart_rx();

		switch((midi_status_t)(midi_msg[0] & 0xF0)) {
			case NoteOff:
				pitch = midi_msg[1];
				velocity = 0;
				break;

			case NoteOn:
				pitch = midi_msg[1];
				velocity = midi_msg[2];
				break;

			default:
				break;
		}
	}
}

uint8_t get_velocity(void) {
	return velocity;
}

uint8_t get_pitch(void) {
	return pitch;
}