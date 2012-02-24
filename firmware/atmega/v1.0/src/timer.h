/**
@file timer.h
@brief
*/

#ifndef SYNTH_TIMER
#define SYNTH_TIMER

#include <avr/io.h>

typedef void (*timer_callback_t)(void);

void timer_init(timer_callback_t, timer_callback_t);

#endif