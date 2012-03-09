/**
\file adsr.c
\brief
*/

#include "adsr.h"

uint8_t times[5] = {0, 5, 25, 30, 60};
uint8_t levels[5] = {0, 200, 170, 170, 0};

uint8_t gate = 0;
uint8_t cur_time = 0xFF;

void trig_gate(uint8_t new_gate) {
	if(new_gate > 0 && gate == 0) cur_time = 0;
	gate = new_gate;
}

uint8_t adsr_value(void) {
	if(cur_time >= times[4]) {
		return 0;
	} else {
		uint8_t value = 0;
		uint8_t i;
		for(i = 0;i < 5;i++) {
			if(cur_time < times[i]) {
				value = levels[i]-(levels[i]-levels[i-1])*(times[i]-cur_time)/(times[i]-times[i-1]);
				break;
			} else if(cur_time == times[i]) {
				value = levels[i];
				break;
			}
		}
		if((gate > 0 && cur_time < times[3]) || gate == 0) cur_time++;
		return value;
	}
}