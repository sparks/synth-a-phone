#include "timer.h"

#include "main.h"
#include "dac.h"
#include "synthesis.h"

#include <avr/interrupt.h>

uint16_t count = 0;

void timer_init(void) {
	TCCR0A = (1 << WGM01) | (0 << WGM00); //CTC mode all outputs detached
	TCCR0B = (0 << WGM02) | 2; //1024 prescale

	OCR0A = 0x35; //A Period x2D
	// OCR0B = 0xFF; //B Period

	TIMSK0 = (0 << OCIE0B) | (1 << OCIE0A); //Interrupt enable 0A 0B
}

ISR(TIMER0_COMPA_vect) {
	serial_dac(main_out());
	trigger_computation();
}