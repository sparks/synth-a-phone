#ifndef SYNTH_ADC

#include <avr/io.h>

void adc_init(void);
uint8_t get_val8(void);
uint16_t get_val12(void);

#endif