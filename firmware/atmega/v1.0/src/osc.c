/**
@file osc.c
*/

#include "osc.h"
#include <math.h>

#define WAVETABLE_WIDTH 500
#define PI 3.14159265

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max);

uint8_t direction = 0;
uint16_t count = 0;
uint16_t ramp_saw = 0;
uint16_t ramp_tri = 0;
uint16_t ramp_squ = 0;
uint16_t ramp_sin = 0;

uint16_t sine_lookup[WAVETABLE_WIDTH];

void sine_init(void) {
	int i;
	for (i = 0; i < WAVETABLE_WIDTH; i++) {
		// creates a lookup table of one wavelength of sine of WAVETABLE_WIDTH
		// first offset by 1 because it's unsigned
		// multiplied by the halfwidth of the 12bit dac
		sine_lookup[i] = (uint16_t)((0xFFF >> 1) * (sin(i * 2 * PI / WAVETABLE_WIDTH) + 1));
	}
}

uint16_t sawtooth(uint16_t freq) {
	ramp_saw += freq;
	if(ramp_saw > 0xFFF) ramp_saw = 0;

	return ramp_saw;
}

uint16_t triangle(uint16_t freq) {
	if(direction == 0) ramp_tri += freq << 1;
	else ramp_tri -= freq << 1;

	if(ramp_tri >= 0xFFF) {
		if(direction == 0) ramp_tri = 0xFFF;
		else ramp_tri = 0;
		direction = (direction + 1) % 2;
	}

	return ramp_tri; 
}

uint16_t pulse(uint16_t freq) {
	count += freq;

	if(count >= 0xFFF) {
		if(ramp_squ == 0) ramp_squ = 0xFFF;
		else ramp_squ = 0;
		count = 0;
	}

	return ramp_squ;
}

uint16_t sine(uint16_t freq) {
	ramp_sin += freq;

	if (ramp_sin >= WAVETABLE_WIDTH) ramp_sin = 0;

	return sine_lookup[ramp_sin];
}

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max) {
	if(num > max) return max;
	else if(num < min) return min;
	else return num;
}
