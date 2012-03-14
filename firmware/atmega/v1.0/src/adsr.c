/**
\file adsr.c
\brief Simple linear interpolation sampled ADSR envelope.
*/

#include "adsr.h"

uint8_t times[5] = {0, 5, 20, 5, 30};
uint8_t levels[5] = {0, 200, 170, 170, 0};

uint8_t gate = 0;
uint8_t cur_time = 0xFF;

void adsr_init(void) {
	uint8_t i, j;
	for(i = 0;i < 5;i++) {
		for(j = 0;j < i;j++) {
			times[i] += times[j];
		}
	}
}

void gate(uint8_t new_gate) {
	if(new_gate > 0 && gate == 0) cur_time = 0;
	gate = new_gate;
}

uint8_t compute_adsr(void) {
	if(cur_time >= times[4]) { //If the time index is past the end of the envelope, the envelope is finished
		return 0; //Thus return zero
	} else { //Otherwise we will need to compute the value
		uint8_t value = 0;
		uint8_t i;
		for(i = 0;i < 5;i++) {
			if(cur_time < times[i]) { //Check what segment we're in
				value = levels[i]-(levels[i]-levels[i-1])*(times[i]-cur_time)/(times[i]-times[i-1]); //Compute the linear interpolation
				break;
			} else if(cur_time == times[i]) { //Check if we're exactly on a point
				value = levels[i]; 
				break;
			}
		}
		if((gate > 0 && cur_time < times[3]) || gate == 0) cur_time++; //If we haven't reached the sustain point, or if we've released, keep incrementing index
		return value;
	}
}