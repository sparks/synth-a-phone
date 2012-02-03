/**
@file timer.c
@brief
*/

#include "timer.h"

#include "main.h"
#include "dac.h"

#include <avr/interrupt.h>

timer_callback callback;

void timer_init(timer_callback c, uint8_t interval) {
	callback = c;
	
	TCCR0A = (1 << WGM01) | (0 << WGM00); //CTC mode all outputs detached
	TCCR0B = (0 << WGM02) | 2; //1024 prescale

	OCR0A = interval; //A Period x2D
	// OCR0B = 0xFF; //B Period

	TIMSK0 = (0 << OCIE0B) | (1 << OCIE0A); //Interrupt enable 0A 0B
}

ISR(TIMER0_COMPA_vect) {
	(*callback)();
}

