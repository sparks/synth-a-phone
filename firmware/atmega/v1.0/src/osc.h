/**
\file osc.h
\brief Contains all the wavegeneration/oscillator code
*/

#ifndef SYNTH_OSCILLATORS
#define SYNTH_OSCILLATORS

#include <avr/io.h>

/** typedef for wave table index */
typedef union {
	uint32_t int32;
	uint8_t array[4];
} audio_index_t;

/** 24bit addition macro */
#define add_audio_index(a, b) \
	__asm__ __volatile__( \
			"add %0, %3" "\n\t" \
			"adc %1, %4" "\n\t" \
			"adc %2, %5" "\n\t" : \
			"+r" (a.array[0]), "+r" (a.array[1]), "+r" (a.array[2]), \
			"+r" (b.array[0]), "+r" (b.array[1]), "+r" (b.array[2]) \
	)
#endif

/**
 * Initialises various variables and tables for the oscillators.
 *
*/
void osc_init(void);

/**
 * Returns a exact sawtooth wave, not bandlimited, computed on the fly.
 *
 * \param freq the frequency increment.
 * \return the next wave value.
*/
int16_t sawtooth(uint16_t freq);

/**
 * Returns a exact triangle, not bandlimited, computed on the fly.
 *
 * \param freq the frequency increment.
 * \return the next wave value.
*/
int16_t triangle(uint16_t freq);

/**
 * Returns a exact 50/50 duty cycle pulse, not bandlimited, computed on the fly.
 *
 * \param freq the frequency increment.
 * \return the next wave value.
*/
int16_t pulse(uint16_t freq);

/**
 * Takes as input 24 bit (8x3 array) freq (period) encoded inside a 32bit int using the audio_index_t type.
 * ramp_sin is incremented by freq and the last byte is used in the look up table to get the sine value.
 *
 * \param freq the frequency increment.
 * \return the next wave value.
*/
int16_t sine(audio_index_t freq);
