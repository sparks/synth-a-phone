/**
@file distortion.c
@brief
*/

#include "distortion.h"

#define MAX 1024

void clip(uint16_t *val) {

	if(*val > 3095) *val = 3095;
	else if(*val < 1000) *val = 1000;

}
