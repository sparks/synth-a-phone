/**
@file effects.h
@brief
*/

#ifndef SYNTH_EFFECTS
#define SYNTH_EFFECTS

#include <avr/io.h>

int low_pass(int16_t* yn);
void clip(int16_t* val);

#endif
