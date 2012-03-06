/**
@file adsr.h
@brief
*/

#ifndef SYNTH_ADSR
#define SYNTH_ADSR

#include <avr/io.h>

void trig_gate(uint8_t gate);
uint8_t adsr_value(void);

#endif