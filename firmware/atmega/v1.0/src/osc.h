/**
@file osc.h
@brief
*/

#ifndef SYNTH_OSCILLATORS
#define SYNTH_OSCILLATORS

#include <avr/io.h>

void sine_init(void);

uint16_t sawtooth(uint16_t freq);
uint16_t triangle(uint16_t freq);
uint16_t pulse(uint16_t freq);
uint16_t sine(uint16_t freq);

#endif