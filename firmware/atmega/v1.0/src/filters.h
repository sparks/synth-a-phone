#ifndef FILTERS_H_
#define FILTERS_H_

#include <avr/io.h>

#define FILTER_1_ORDER 5

uint16_t x_n[FILTER_1_ORDER];
uint16_t y_n[FILTER_1_ORDER];

int low_pass(uint16_t* yn);

#endif
