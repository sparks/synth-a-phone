/**
@file effects.c
@brief
*/

#include "effects.h"

#define FILTER_1_ORDER 5
#define MAX 1024

int16_t x_n[FILTER_1_ORDER];
int16_t y_n[FILTER_1_ORDER];

int low_pass(int16_t* yn) {
	return *yn;	
}

void clip(int16_t *val) {
	
	if(*val > MAX) *val = MAX;
	else if(*val < -MAX) *val = -MAX;
}
