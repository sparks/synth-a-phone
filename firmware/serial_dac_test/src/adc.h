/**
@file adc.h
@brief Header file for the adc control
*/

#ifndef SYNTH_ADC
#define SYNTH_ADC

#include <avr/io.h>

#define ADC_ERROR_CODE 0xFFFF

/**
@brief asdfff sdf
*/
void adc_init(void);

uint16_t adc_val(uint8_t);

#endif