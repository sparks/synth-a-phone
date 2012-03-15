/**
\file midi.c
\brief
*/

#include "uart.h"
#include "midi.h"
#include "adsr.h"

void pitch_change(void);
void uart_callback(void);

uint8_t midi_msg[3]; //Buffer for the latest MIDI message

uint8_t pitch = 69; //Start with middle C
uint8_t velocity = 0; //Off

uint32_t deltas[13] = {0x000EBC19, 0x000F9C66, 0x00108A09, 0x001185CE, 0x0012908B, 0x0013AB25, 0x0014D68D, 0x001613C2, 0x001763D4, 0x0018C7E3, 0x001A411D, 0x001BD0C5, 0x001D7831};
uint32_t cur_delta = 0;

void midi_init(void) {
	uart_init(&uart_callback);
}

uint8_t get_velocity(void) {
	return velocity;
}

uint8_t get_pitch(void) {
	return pitch;
}

uint32_t get_delta(void) {
	return cur_delta;
}

void uart_callback(void) {
	if(uart_available() >= 3) {
		midi_msg[0] = uart_rx();
		if((midi_msg[0] & 0x80) == 0) return; //This realigns the MIDI messages
		midi_msg[1] = uart_rx();
		midi_msg[2] = uart_rx();

		switch((midi_status_t)(midi_msg[0] & 0xF0)) {
			case NoteOn:
				if(midi_msg[2] != 0) {
					pitch = midi_msg[1];
					velocity = midi_msg[2];
					pitch_change();
					gate(0); //Reset the adsr
					gate(1); //Trigger
					break;
				}

			case NoteOff:
				if(pitch == midi_msg[1]) { //Turn off only if it's the current note since this is a monophonic synth
					velocity = 0;
					gate(0); //Release
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

	cur_delta = ((deltas[note]) << octave) & 0x00FFFFFF;
}