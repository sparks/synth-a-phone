/**
\file main.c
\brief main process for the synth project.
*/

#include "main.h"

#include "adc.h"
#include "dac.h"
#include "timer.h"
#include "uart.h"
#include "midi.h"

#include "adsr.h"
#include "osc.h"
#include "effects.h"

#include <avr/interrupt.h>
#include <util/delay.h>

// #define USING_KEYS //Comment out if you don't have a MIDI keyboard

void hf_sample(void);
void lf_sample(void);
int16_t apply_env(uint8_t env, int16_t value);

volatile uint8_t too_slow_flag = 0;
volatile int8_t compute_flag = 0;

audio_index_t freq[3];
int16_t hif_output = 0;
uint8_t env = 255;

/**
 * Main function
 *
 * \return the exit code of the program (don't care).
*/
int main(void) {

	adc_init();
	dac_init();
	adsr_init();
	
	midi_init();
	osc_init();

	//initialize sines
	audio_index_t sine1, sine2;
	sine1.uint32_t = sine2.uint32_t = 0x0;
	
	timer_init(&hf_sample, &lf_sample); //This should be last, since timer callback will start occuring after this
	sei();

	for(;;) {
		if(compute_flag != 0) {
			hif_output = 0;
			
			#ifdef USING_KEYS			
				if(adc_val(1) < 350) {
					hif_output += apply_env(env, sine(freq));
				} else if(adc_val(1) < 700) {
					hif_output += apply_env(env, sawtooth(freq.array[2]));
				} else {
					hif_output += apply_env(env, triangle(freq.array[2]));
				}
			#else
				//compare just look up table vs linear interpolation
				if(adc_val(2) < (500)) {
					//only look up table
					hif_output += sine(&sine1, freq[0]);

				} else {
					//sine with linear interpolation
					hif_output += sine_interpolated(&sine2, freq[0]);
				}

				// Stacked wave.
				//hif_output += triangle(freq[2]<<2)>>1;
			
				/*
				if (adc_val(0) > 512) {
					clip(&hif_output);
				} */
			#endif
			
			compute_flag = 0;
		}
	}
	
	return 0;
}

/**
 * Call back for the high frequency timer, used for audio sampling rate.
 *
*/
void hf_sample(void) {
	if(compute_flag == 0) {
		// if(too_slow_flag == 0) {
			serial_dac(hif_output+2048);
			// par_dac(hif_output);
			compute_flag = 1;
		// }
	} else {
		too_slow_flag = 1;
	}
}

/**
 * Call back for the low frequency timer, used for envelope sampling rate, LFOs, ADCs and other slow buisness.
 *
*/
void lf_sample(void) {
	#ifdef USING_KEYS
		// env = compute_adsr();
		freq.uint32_t = get_delta();
		audio_index_t detune;
		detune.array[1] = (adc_val(0) >> 2) & 0xFF;
		detune.array[0] = (adc_val(2) >> 2) & 0xFF;
		add_audio_index(freq, detune);
	#else
	
		/* one pot freq control */
		freq[0].uint32_t = ((uint32_t)adc_val(0)) << 12;
		freq[1].uint32_t = ((uint32_t)adc_val(2)) << 12;
		freq[2].uint32_t = ((uint32_t)adc_val(1)) << 12;
		
		
		/* three pot freq control
		freq.array[2] = adc_val(0) >> 2;
		freq.array[1] = adc_val(2) >> 2;
		freq.array[0] = adc_val(1) >> 2;

		if(freq.uint32_t > 0xA3D000) freq.uint32_t = 0xA3D000; //max freq
		else if(freq.uint32_t < 0x2000) freq.uint32_t = 0x2000; //min freq
		*/

	#endif

	adc_trigger();
}

/**
 * Applies the envelope to the given 12bit signal value.
 *
 * \param env the current envelope value (255 -> 1, 0 -> 0)
 * \param value the 12bit signal value
 * \return the enveloped value
*/
int16_t apply_env(uint8_t env, int16_t value) {
	return ((value >> 4)*env) >> 4;
}

