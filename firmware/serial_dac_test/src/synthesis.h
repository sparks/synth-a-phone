/**
@file synthesis.h
@brief
*/

#ifndef SYNTH_SYNTHESIS
#define SYNTH_SYNTHESIS

#include <avr/io.h>

uint16_t sawtooth(uint16_t freq);
uint16_t triangle(uint16_t freq);

#endif