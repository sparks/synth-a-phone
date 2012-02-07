/**
@file wavetable.h
@brief
*/

#ifndef SYNTH_WAVETABLE
#define SYNTH_WAVETABLE

#include <avr/io.h>

#define WAVETABLE_WIDTH 500

uint16_t sine_lookup[WAVETABLE_WIDTH];

void sine_init(void);

#endif