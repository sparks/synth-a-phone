/**
@file osc.h
@brief
*/

#ifndef SYNTH_OSCILLATORS
#define SYNTH_OSCILLATORS

#include <avr/io.h>

// 3 x 8 bit definition
typedef uint8_t uint24_t[3];

void sine_init(void);

uint16_t sawtooth(uint16_t freq);
uint16_t triangle(uint16_t freq);
uint16_t pulse(uint16_t freq);
uint16_t sine(uint16_t freq);

void add_uint24(uint24_t a, uint24_t b, uint24_t result);
void sine_uint24(uint24_t freq, uint24_t out);
#endif
