/**
\file dac.h
\brief Provides access to output value to the serial and parallel DAC.
*/

#ifndef SYNTH_DAC
#define SYNTH_DAC

#include <avr/io.h>

/**
 * Setup the pins, configure the interrupts and initialize values for the DAC.
 *
*/
void dac_init(void);

/**
 * Send a sample to the DAC to be rendered. The serial DAC is a 12 bit DAC, thus all values will be truncated to 12 bits.
 *
 * \param value the value to send to the DAC.
*/
void serial_dac(uint16_t value);

/**
 * Send a sample to the DAC to be rendered. The serial DAC is a 16 bit DAC, thus no truncation will occur.
 *
 * \param value the value to send to the DAC.
*/
void par_dac(uint16_t value);

/**
 * Check to see if the DACs are idle.
 *
 * \return if the value is non zero, the DACs are idle.
*/
uint8_t is_idle(void);

/**
 * Check to see if a new value was sent to the DAC before the last value was successfully outputted, e.g. if loss has occurred.
 *
 * \return if the value is non zero, loss has occurred.
*/
uint8_t is_lossy(void);

#endif

