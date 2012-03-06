/**
@file adsr.c
@brief
*/

#include "adsr.h"

uint8_t times[5] = {0, 5, 25, 26, 126};
int8_t levels[5] = {0, 127, 60, 30, 0};

uint8_t gate = 0;
uint8_t cur_time = 0xFF;

void trig_gate(uint8_t val) {
	if(val == 1 && gate == 0) cur_time = 0;
	gate = val;
}

uint8_t adsr_value(void) {
	if(cur_time >= times[3]) return 0;
	else {
		int8_t value = 0;
		uint8_t i;
		for(i = 0;i < 4;i++) {
			if(cur_time < times[i]) {
				value = (levels[i]-levels[i-1])*(times[i]-cur_time)/(times[i]-times[i-1]);
			}
		}
		if((gate == 1 && cur_time < times[2]) || (gate == 0 && cur_time < times[3])) cur_time++;
		return 0;
	}
}