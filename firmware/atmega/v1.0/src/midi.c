/**
@file midi.c
@brief
*/

#include "midi.h"
#include "uart.h"
#include "adsr.h"

uint8_t pitch = 100;
uint8_t velocity = 0;
uint8_t midi_msg[3];

//freq = 440 * 2^((n-60)/12)

//Octave 0 MIDI reference
// Middle	0	60	C	261.6255653006	-900.00
// Middle	0	61	C#/Db	277.1826309769	-800.00
// Middle	0	62	D	293.6647679174	-700.00
// Middle	0	63	D#/Eb	311.1269837221	-600.00
// Middle	0	64	E	329.6275569129	-500.00
// Middle	0	65	F	349.2282314330	-400.00
// Treble	0	66	F#/Gb	369.9944227116	-300.00
// Treble	0	67	G	391.9954359817	-200.00
// Treble	0	68	G#/Ab	415.3046975799	-100.00
// Treble	0	69	A	440.0000000000	0.00
// Treble	0	70	A#/Bb	466.1637615181	100.00
// Treble	0	71	B	493.8833012561	200.00

void uart_callback(void) {
	if(uart_available() >= 3) {
		midi_msg[0] = uart_rx();
		if((midi_msg[0] & 0x80) == 0) return;
		midi_msg[1] = uart_rx();
		midi_msg[2] = uart_rx();

		switch((midi_status_t)(midi_msg[0] & 0xF0)) {
			case NoteOn:
				if(midi_msg[2] != 0) {
					pitch = midi_msg[1];
					velocity = midi_msg[2];
					trig_gate(0);
					trig_gate(1);
					break;
				}

			case NoteOff:
				if(pitch == midi_msg[1]) {
					velocity = 0;
					trig_gate(0);
				}
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