/**
@file osc.h
@brief
*/

#ifndef SYNTH_OSCILLATORS
#define SYNTH_OSCILLATORS

#include <avr/io.h>

void sine_init(void);

int16_t sawtooth(uint16_t freq);
int16_t triangle(uint16_t freq);
int16_t pulse(uint16_t freq);
int16_t sine(uint16_t freq);

int16_t sine_uint24(uint8_t* freq);
#endif
