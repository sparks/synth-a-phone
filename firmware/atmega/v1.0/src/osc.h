/**
\file osc.h
\brief
*/

#ifndef SYNTH_OSCILLATORS
#define SYNTH_OSCILLATORS

#include <avr/io.h>

void sine_init(void);

int16_t sawtooth(uint16_t freq);
int16_t triangle(uint16_t freq);
int16_t pulse(uint16_t freq);
int16_t sine(uint16_t freq);

//typedef for wave table index
typedef union {
	uint32_t int32;
	uint8_t array[4];
} audio_index_t;

int16_t sine_uint24(audio_index_t freq);

// 24bit addition macro 
#define add_audio_index(a, b) \
	__asm__ __volatile__( \
			"add %0, %3" "\n\t" \
			"adc %1, %4" "\n\t" \
			"adc %2, %5" "\n\t" : \
			"+r" (a.array[0]), "+r" (a.array[1]), "+r" (a.array[2]), \
			"+r" (b.array[0]), "+r" (b.array[1]), "+r" (b.array[2]) \
	)
#endif
