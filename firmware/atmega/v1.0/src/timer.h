/**
\file timer.h
\brief Provide simple implementation for two timers (8bit and 16bit), one low frequency and one highfrequency, with callbacks.
*/

#ifndef SYNTH_TIMER
#define SYNTH_TIMER

#include <avr/io.h>

/**
 * The type for a timer callback function pointer.
 *
*/
typedef void (*timer_callback_t)(void);

/**
 * Setup the two timers. One high frequency timer (8bit) and one low frequency timer (16bit). The function takes two function pointers to be used as callback for the two timers.
 *
 * The frequencies of the two timers are set by defines.
 *
 * \param hf the high frequency callback.
 * \param lf the low frequency callback.
*/
void timer_init(timer_callback_t hf, timer_callback_t lf);

#endif