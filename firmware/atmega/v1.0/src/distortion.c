/**
@file distortion.c
@brief
*/

#include "distortion.h"

#define MAX 1024

void clip(uint16_t *val) {

	*val <<= 2;
}
