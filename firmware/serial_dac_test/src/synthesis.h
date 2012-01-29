#ifndef SYNTH_SYNTHESIS
#define SYNTH_SYNTHESIS

#include <avr/io.h>

void sawtooth(uint16_t freq);

uint16_t main_out(void);

#endif