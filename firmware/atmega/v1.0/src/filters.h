/**
@file filters.h
@brief
*/

#ifndef FILTERS_H
#define FILTERS_H

#include <avr/io.h>

#define FILTER_1_ORDER 5

uint16_t x_n[FILTER_1_ORDER];
uint16_t y_n[FILTER_1_ORDER];

int low_pass(uint16_t* yn);

#endif
