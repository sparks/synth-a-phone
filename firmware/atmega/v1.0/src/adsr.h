/**
\file adsr.h
\brief Simple linear interpolation sampled ADSR envelope.
*/

#ifndef SYNTH_ADSR
#define SYNTH_ADSR

#include <avr/io.h>

/**
 * Do a little be of precomputation for the ADSR.
 *
*/
void adsr_init(void);

/**
 * Change the ADSR gate value. Works like a normal envelope gate.
 * <ul>
 * <li>If the value passes from 0 to 1 the envelope is (re)triggered.</li>
 * <li>While the gate remains 1 the envelope will hold at the sustain value.</li>
 * <li>If the gate value goes from 1 to 0 the envelope will play through to it's release point (unless interrupted by a retriggering).</li>
 * </ul>
 *
 * \param new_gate the new gate value.
*/
void gate(uint8_t new_gate);

/**
 * Compute the next cycle envelope value. This should be called by the timer which controls the envelope sampling rate.
 *
 * \return the latest envelope value.
*/
uint8_t compute_adsr(void);

#endif