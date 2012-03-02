/**
@file timer.c
@brief
*/

#include "timer.h"

#include "main.h"
#include "dac.h"

#include <avr/interrupt.h>

#define TIMER_HF_FREQ	31250 //~ 55k max for para and ~45k for ser
#define TIMER_HF_PERIOD	F_CPU/8/TIMER_HF_FREQ

#define TIMER_LF_FREQ 40
#define TIMER_LF_PERIOD F_CPU/8/TIMER_LF_FREQ

timer_callback_t hf_timer_callback;
timer_callback_t lf_timer_callback;

void timer_init(timer_callback_t hf, timer_callback_t lf) {
	hf_timer_callback = hf;
	lf_timer_callback = lf;
	
	TCCR0A = (1 << WGM01) | (0 << WGM00); //CTC mode all outputs detached
	TCCR0B = (0 << WGM02) | (0 << CS02) | (1 << CS01) | (0 << CS00); //8 prescale

	OCR0A = TIMER_HF_PERIOD;

	TCCR1A = (0 << WGM11) | (0 << WGM10); //CTC mode all outputs detached
	TCCR1B = (0 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (0 << CS10); //8 prescale

	OCR1AH = (TIMER_LF_PERIOD >> 8) & 0xFF;
	OCR1AL = TIMER_LF_PERIOD & 0xFF;

	TIMSK0 = (0 << OCIE0B) | (1 << OCIE0A); //Interrupt enable 0A
	TIMSK1 = (0 << OCIE1B) | (1 << OCIE1A); //Interrupt enable 1A
}

ISR(TIMER0_COMPA_vect) {
	(*hf_timer_callback)();
}


ISR(TIMER1_COMPA_vect) {
	(*lf_timer_callback)();
}