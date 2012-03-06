/**
@file effects.h
@brief
*/

#ifndef SYNTH_EFFECTS
#define SYNTH_EFFECTS

#include <avr/io.h>

int low_pass(uint16_t* yn);
void clip(uint16_t* val);

#endif
