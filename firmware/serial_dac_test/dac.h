#ifndef SYNTH_DAC
#define SYNTH_DAC

#include <avr/io.h>

#define DAC_SCK PB5
#define DAC_DIN PB3
#define DAC_CS PB2
#define DAC_LDAC PB1

#define DAC_CONF 0x30

void dac_init(void);

void serial_dac(uint16_t);

#endif