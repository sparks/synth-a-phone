#include "synthesis.h"

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max);

uint8_t direction = 0;
uint16_t ramp = 0;

uint16_t output = 0;

void sawtooth(uint16_t freq) {
	// if(direction == 0) ramp += freq;
	// else ramp -= freq;

	// if(ramp >= 0xFFF || ramp == 0) {
	// 	if(direction == 0) ramp = 0xFFF;
	// 	else ramp = 0;
	// 	direction = (direction+1)%2;
	// }

	ramp += freq;
	if(ramp > 0xFFF) ramp = 0;

	output = ramp;
}

uint16_t main_out(void) {
	return output;
}

uint16_t constrain(uint16_t num, uint16_t min, uint16_t max) {
	if(num > max) return max;
	else if(num < min) return min;
	else return num;
}
