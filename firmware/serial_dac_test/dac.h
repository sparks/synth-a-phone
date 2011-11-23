#ifndef DAC

#include <avr/io.h>

#define DAC_SCK PB5
#define DAC_DIN PB3
#define DAC_CS PB2
#define DAC_LDAC PB1

#define DAC_CONF 0x30

void dac_init(void);
void dac8(uint8_t data);
void dac12(uint16_t data);
void dac_split(uint8_t data1, uint8_t data2);

#endif