/**
\file adc.h
\brief Provide a mechanism to easily get ADC (PORTC) values with externally controlled sampling rate.
*/

#ifndef SYNTH_ADC
#define SYNTH_ADC

#include <avr/io.h>

#define ADC_ERROR_CODE 0xFFFF

/**
 * Setup all the relevant pins and registers to run the ADC. The range of ADC pins is set using defines. No ADC conversion will be performed until adc_trigger() is called.
 *
*/
void adc_init(void);

/**
 * Triggers on run of ADC conversion, e.g. one conversion is done for every pin in the ADC range.
 *
 */
void adc_trigger(void);

/**
 * Returns the ADC val with the specific index in the range of active ADC pins.
 *
 * \param mux the index of the ADC value to be returned.
 * \return the ADC value.
*/
uint16_t adc_val(uint8_t mux);

#endif

