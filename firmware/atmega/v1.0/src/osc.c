/**
\file osc.c
\brief Contains all the wavegeneration/oscillator code
*/

#include "osc.h"
#include "uart.h"

#include <math.h>
#include <avr/pgmspace.h>

/** The wavetable size */
#define WAVETABLE_BITS 11

/* properties depending on the wavetable size */
#if WAVETABLE_BITS == 11
	#include		"wavetable_sin2048.h"
	#define WAVETABLE_WIDTH	2048
	#define INDEX_MASK	0x3FF800
	#define INDEX_MAX	0x7FF
	#define INDEX_SHIFT	13

#elif WAVETABLE_BITS == 12
	#include		"wavetable_sin4096.h"
	#define WAVETABLE_WIDTH 4096 
	#define INDEX_MASK 	0xFFF000
	#define INDEX_MAX 	0xFFF;
	#define INDEX_SHIFT	12;

#elif WAVETABLE_BITS == 13
	#include		"wavetable_sin8192.h"
	#define WAVETABLE_WIDTH	8192
	#define INDEX_MASK	0x1FFF000
	#define INDEX_MAX	0x1FFF
	#define INDEX_SHIFT	11
#endif

/* insert some more wavetables */
#include "wavetable_saw256.h"
#include "wavetable_tri256.h"
#include "wavetable_sqr256.h"

/** Mmmm pie */
#define PI 3.14159265


int16_t saw_ramp = 0;

uint8_t tri_direction = 0;
int16_t tri_ramp = 0;

int16_t pulse_value = 0;
uint16_t pulse_ramp = 0;

audio_index_t ramp_sin;

/* new wave table ramps */
audio_index_t saw_ramp_table;
audio_index_t tri_ramp_table;
audio_index_t sqr_ramp_table;

int tables[12];	//to determine which table to use 

void osc_init(void) {
	int i;

	for(i = 0; i < 12; i++){
		tables[i] = 8*pow(2,i)/(31250.0/16777216.0);
	}
	
	//init ramp_sin
	ramp_sin.uint32_t = 0;

	/*for (i = 0; i < WAVETABLE_WIDTH; i++) {
		// creates a lookup table of one wavelength of sine of WAVETABLE_WIDTH
		// multiplied by the halfwidth of the 12bit dac
		sine_lookup[i] = (int16_t)(2047*(sin((i * 2 * PI) / WAVETABLE_WIDTH)));
	}*/
}

int16_t sawtooth(uint16_t freq) {
	saw_ramp += freq;
	if(saw_ramp > 2047) saw_ramp = -2048;

	return saw_ramp;
}

int16_t sawtooth_index(audio_index_t freq) {
	int16_t output = -2048;

	add_audio_index(saw_ramp_table, freq);
	
	if((saw_ramp_table.uint32_t >> 12) > 4095) saw_ramp_table.uint32_t = 0;  
	return output + (saw_ramp_table.uint32_t >> 12);
}

int16_t sawtooth_table(audio_index_t freq) {
	int i;
	int table = 0; //which table to use

	for(i = 0; i < 12; i++) {
		if(freq.uint32_t < tables[i]) table = i;
	}

	add_audio_index(saw_ramp_table, freq);	
	
	return pgm_read_word(&(saw_ramp_tablei[table][saw_ramp_table.array[2]]));
}

int16_t triangle(uint16_t freq) {
	if(tri_direction == 0) tri_ramp += freq << 1;
	else tri_ramp -= freq << 1;

	if(tri_ramp >= 2047 || tri_ramp <= -2048) {
		if(tri_direction == 0) tri_ramp = 2047;
		else tri_ramp = -2048;
		tri_direction = (tri_direction + 1) % 2;
	}

	return tri_ramp;
}

int16_t pulse(uint16_t freq) {
	pulse_ramp += freq;

	if(pulse_ramp >= 0xFFF) {
		if(pulse_value == -2048) pulse_value = 2047;
		else pulse_value = -2048;
		pulse_ramp = 0;
	}

	return pulse_value;
}

int16_t sine(audio_index_t *ramp, audio_index_t freq) {
	add_audio_index((*ramp), freq);

	return pgm_read_word(&(sine_lookup[(*ramp).uint32_t >> INDEX_SHIFT]));
}

int16_t sine_interpolated(audio_index_t *ramp, audio_index_t freq) {
	int16_t val1, val2;
	uint32_t index;

	add_audio_index((*ramp), freq);

	// linear interpolation:
	// F(x) = F(x1) + (x - x1) * (F(x2) - F(x1)/(x2 - x1)
	index = (*ramp).uint32_t >> INDEX_SHIFT;
	val1 = pgm_read_word(&(sine_lookup[index]));

	if(index == INDEX_MAX) index = 0;
	else index++;

	val2 = pgm_read_word(&(sine_lookup[index]));

	return val1+((((signed)((*ramp).uint32_t - ((*ramp).uint32_t & INDEX_MASK)))*(val2 - val1))/WAVETABLE_WIDTH);	//div instead of shift to guarantee arithmetic shift
		
}

