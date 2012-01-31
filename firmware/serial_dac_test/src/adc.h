/**
@file adc.h
@brief
*/

#ifndef SYNTH_ADC
#define SYNTH_ADC

#include <avr/io.h>

#define ADC_ERROR_CODE 0xFFFF

void adc_init(void);

uint16_t adc_val(uint8_t);

#endif

