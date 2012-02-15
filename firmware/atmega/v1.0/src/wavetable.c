/**
@file wavetable.c
@brief
*/

#include <math.h>
#include "wavetable.h"

#define PI 3.14159265

void sine_init(void) {

	int i;
	for (i = 0; i < WAVETABLE_WIDTH; i++) {
		// creates a lookup table of one wavelength of sine of WAVETABLE_WIDTH
		// first offset by 1 because its unsigned
		// multiplied by the halfwidth of the 12bit dac
		sine_lookup[i] = (uint16_t)((0xFFF >> 1) * (sin(i * 2 * PI / WAVETABLE_WIDTH) + 1));
	}
}
