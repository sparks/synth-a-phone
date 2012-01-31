/**
@file timer.h
@brief
*/

#ifndef SYNTH_TIMER
#define SYNTH_TIMER

#include <avr/io.h>

typedef void (*timer_callback)(void);

void timer_init(timer_callback, uint8_t);

#endif

