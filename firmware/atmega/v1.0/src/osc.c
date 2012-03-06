/**
@file osc.c
*/

#include "osc.h"
#include <math.h>

#define WAVETABLE_WIDTH 500
#define PI 3.14159265

uint8_t direction = 0;

int16_t ramp_saw = 0;
int16_t ramp_tri = 0;

int16_t squ_value = 0;
uint16_t ramp_squ = 0;
uint16_t ramp_sin = 0;

int16_t sine_lookup[WAVETABLE_WIDTH];

void sine_init(void) {
	int i;
	for (i = 0; i < WAVETABLE_WIDTH; i++) {
		// creates a lookup table of one wavelength of sine of WAVETABLE_WIDTH
		// first offset by 1 because it's unsigned
		// multiplied by the halfwidth of the 12bit dac
		sine_lookup[i] = (int16_t)(2047*(sin(i * 2 * PI / WAVETABLE_WIDTH)));
	}
}

int16_t sawtooth(uint16_t freq) {
	ramp_saw += freq;
	if(ramp_saw > 2047) ramp_saw = -2048;

	return ramp_saw;
}

int16_t triangle(uint16_t freq) {
	if(direction == 0) ramp_tri += freq << 1;
	else ramp_tri -= freq << 1;

	if(ramp_tri >= 2047 || ramp_tri <= -2048) {
		if(direction == 0) ramp_tri = 2047;
		else ramp_tri = -2048;
		direction = (direction + 1) % 2;
	}

	return ramp_tri;
}

int16_t pulse(uint16_t freq) {
	ramp_squ += freq;

	if(ramp_squ >= 0xFFF) {
		if(squ_value == -2048) squ_value = 2047;
		else squ_value = -2048;
		ramp_squ = 0;
	}

	return squ_value;
}

int16_t sine(uint16_t freq) {
	ramp_sin += freq;

	if (ramp_sin >= WAVETABLE_WIDTH) ramp_sin = 0;

	return sine_lookup[ramp_sin];
}