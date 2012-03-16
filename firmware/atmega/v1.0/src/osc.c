/**
\file osc.c
\brief Contains all the wavegeneration/oscillator code
*/

#include "osc.h"
#include "uart.h"

#include <math.h>
#include <avr/pgmspace.h>

/** The default wavetable length */
#define WAVETABLE_WIDTH 4096 

#if WAVETABLE_WIDTH == 4096
#include "wavetable_sin4096.h"
// placeholder for other possible tables
#endif
 
/** Mmmm pie */
#define PI 3.14159265


int16_t saw_ramp = 0;

uint8_t tri_direction = 0;
int16_t tri_ramp = 0;

int16_t pulse_value = 0;
uint16_t pulse_ramp = 0;

int16_t val1, val2;

audio_index_t ramp_sin;

void osc_init(void) {
	//int i;
	
	//init ramp_sin
	ramp_sin.uint32_t = 0;

	/*for (i = 0; i < WAVETABLE_WIDTH; i++) {
		// creates a lookup table of one wavelength of sine of WAVETABLE_WIDTH
		// multiplied by the halfwidth of the 12bit dac
		sine_lookup[i] = (int16_t)(2047*(sin((i * 2 * PI) / WAVETABLE_WIDTH)));
	}*/
}

int16_t sawtooth(uint16_t freq) {
	saw_ramp += freq;
	if(saw_ramp > 2047) saw_ramp = -2048;

	return saw_ramp;
}

int16_t triangle(uint16_t freq) {
	if(tri_direction == 0) tri_ramp += freq << 1;
	else tri_ramp -= freq << 1;

	if(tri_ramp >= 2047 || tri_ramp <= -2048) {
		if(tri_direction == 0) tri_ramp = 2047;
		else tri_ramp = -2048;
		tri_direction = (tri_direction + 1) % 2;
	}

	return tri_ramp;
}

int16_t pulse(uint16_t freq) {
	pulse_ramp += freq;

	if(pulse_ramp >= 0xFFF) {
		if(pulse_value == -2048) pulse_value = 2047;
		else pulse_value = -2048;
		pulse_ramp = 0;
	}

	return pulse_value;
}

int16_t sine(audio_index_t freq) {
	add_audio_index(ramp_sin, freq);

	#if WAVETABLE_WIDTH == 4096
		val1 = pgm_read_word(&(sine_lookup[ramp_sin.uint32_t >> 12]));
		val2 = pgm_read_word(&(sine_lookup[(ramp_sin.uint32_t+1) >> 12]));
		
		return val1+(((ramp_sin.uint32_t - (ramp_sin.uint32_t & 0xFFFFF000))*(val1 - val2)) >> 12);
	
	// placeholder for other possible tables
	#endif
}

