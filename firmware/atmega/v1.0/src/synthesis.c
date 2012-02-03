/**
@file synthesis.c
@brief
*/

#include "synthesis.h"
#include "wavetable.h"

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max);

uint8_t direction = 0;
uint16_t count = 0;
uint16_t ramp_saw = 0;
uint16_t ramp_tri = 0;
uint16_t ramp_squ = 0;
uint16_t ramp_sin = 0;

uint16_t sawtooth(uint16_t freq) {
	ramp_saw += freq;
	if(ramp_saw > 0xFFF) ramp_saw = 0;

	return ramp_saw;
}

uint16_t triangle(uint16_t freq) {
	if(direction == 0) ramp_tri += freq;
	else ramp_tri -= freq;

	if(ramp_tri >= 0xFFF || ramp_tri == 0) {
		if(direction == 0) ramp_tri = 0xFFF;
		else ramp_tri = 0;
		direction = (direction + 1) % 2;
	}

	return ramp_tri; 
}

uint16_t square(uint16_t freq) {
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

