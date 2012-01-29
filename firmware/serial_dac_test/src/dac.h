/**
@file dac.h
@brief
*/

#ifndef SYNTH_DAC
#define SYNTH_DAC

#include <avr/io.h>

void dac_init(void);

// void serial_dac_blocking(uint16_t);
void serial_dac(uint16_t);

uint8_t is_idle(void);
uint8_t is_lossy(void);

#endif