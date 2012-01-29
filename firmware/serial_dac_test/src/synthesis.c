/**
@file synthesis.c
@brief
*/

#include "synthesis.h"

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max);

uint8_t direction = 0;
uint16_t ramp_saw = 0;
uint16_t ramp_tri = 0;

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
		direction = (direction+1)%2;
	}

	return ramp_tri; 
}

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max) {
	if(num > max) return max;
	else if(num < min) return min;
	else return num;
}
