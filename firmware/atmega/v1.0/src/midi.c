/**
@file midi.c
@brief
*/

#include "midi.h"
#include "uart.h"
#include "adsr.h"

uint8_t pitch = 69;
uint8_t velocity = 100;
uint8_t midi_msg[3];
uint32_t deltas[13] = {0x000EBC19, 0x000F9C66, 0x00108A09, 0x001185CE, 0x0012908B, 0x0013AB25, 0x0014D68D, 0x001613C2, 0x001763D4, 0x0018C7E3, 0x001A411D, 0x001BD0C5, 0x001D7831};
uint8_t cur_delta[3] = {0,0,1};

void pitch_change(void);

//delta = 2 ^ 24 * Freq / SamplingFreq
// 440 * 2 ^ ((n - 69 + d) / 12)
//freq = 440 * 2^((n-60)/12)
//delta = 2 ^ 24 * 440 * 2 ^ (n-69)/12 /samp

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
					pitch_change();
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

void pitch_change(void) {
	uint8_t octave = 0;
	uint8_t note = pitch;
	while(note >= 12) {
		note -= 12;
		octave++;
	}
	// uint32_t delta = deltas[note+1]-deltas[note];
	// delta = delta*(octave << 8);
	// delta += deltas[note];
	uint32_t delta = (deltas[note]) << octave;
	cur_delta[0] = (delta >> 8) & 0x000000FF;
	cur_delta[1] = (delta >> 16) & 0x000000FF;
	cur_delta[2] = (delta >> 24) & 0x000000FF;
}

uint8_t get_velocity(void) {
	return velocity;
}

uint8_t get_pitch(void) {
	return pitch;
}

void get_delta(uint8_t* freqray) {
	freqray[0] = cur_delta[0];
	freqray[1] = cur_delta[1];
	freqray[2] = cur_delta[2];
}