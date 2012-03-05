/**
@file effects.c
@brief
*/

#include "effects.h"

#define FILTER_1_ORDER 5
#define MAX 1024

uint16_t x_n[FILTER_1_ORDER];
uint16_t y_n[FILTER_1_ORDER];

int low_pass(uint16_t* yn) {
	return *yn;	
}

void clip(uint16_t *val) {
	if(*val > 3095) *val = 3095;
	else if(*val < 1000) *val = 1000;
}
