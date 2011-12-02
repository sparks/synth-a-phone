#include "main.h"
#include "dac.h"
#include "adc.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

uint8_t RESOLUTION = 50;

uint8_t sintable[50]; //sin 8bit
// uint16_t sintable[50]; //sin 12bit

int main(void) {
	dac_init();
	adc_init();

	sei();

	// TCCR0A = (1 << WGM01) | (0 << WGM00); //CTC mode all outputs detached
	// TCCR0B = (0 << WGM02) | (0 << CS02) | (0 << CS01) | (1 < CS00); //No prescale

	// OCR0A = 0xFF; //A Period
	// OCR0B = 0xFF; //B Period

	// TIMSK0 = (1 << OCIE0B) | (1 << OCIE0A); //Interrupt enable 0A 0B

	/*uint8_t i, j;

	for(i = 0;;i++) {
		uint8_t val = get_val8();
		dac8(i);
		for(j = 0;j < val-4;j += 4) _delay_us(1);
	}*/

	//sin 8bit
	/*uint8_t i;

	for(i = 0;i < RESOLUTION;i++) {
		sintable[i] = 0xFF & (uint8_t)round((sin(M_PI*2/RESOLUTION*i)+1)*0x7F);
	}
	
	uint8_t new_val;
	uint8_t val = get_val8();
	
	for(;;) {
		new_val = get_val8();
		if((new_val > val && new_val-val > 10) || (val > new_val && val-new_val > 10)) {
			RESOLUTION = new_val;
			for(i = 0;i < RESOLUTION;i++) {
				sintable[i] = 0xFF & (uint8_t)round((sin(M_PI*2/RESOLUTION*i)+1)*0x7F);
			}
			val = new_val;
		}
		for(i = 0;i < RESOLUTION;i++) {
			dac8(sintable[i]);
		}
	}*/

	//sin 12bit
	/*uint16_t i;

	for(i = 0;i < RESOLUTION;i++) {
		sintable[i] = 0xFFF & (uint16_t)round((sin(M_PI*2/RESOLUTION*i)+1)*0x7FF);
	}
	
	for(;;) {
		for(i = 0;i < RESOLUTION;i++) {
			dac12(sintable[i]);
		}
	}*/

	//generative
	/*uint32_t t;

	for(t = 0;;t++) {
		dac8(t*5&(t>>7)|t*3&(t*4>>10));
		_delay_us(100);
	}*/

	//triangle 8bit
	/*uint8_t i, k;
	k = 1;

	for(;;) {
		for(i = 0;i < 0xFF;i += k) {
			dac8(i);
			if(get_val() > 0x7F) k = 3;
			else k = 1;
		}
	}*/

	//triangle 12bit (faster)
	/*uint8_t i, j;

	for(;;) {
		for(i = 0;i < 0xF;i++) {
			for(j = 0;j < 0xFF;j++) {
				dac_split(i, j);
			}
		}
	}*/

	// triangle 12bit
	uint16_t i;
	uint16_t val1, val2, val3;

	for(;;) {
		for(i = 0;i < 0xFFF;i += 100) {
			val1 = adc_val(0);

			if(val1 > 500) _delay_us(100);
			else _delay_us(50);

			serial_dac(i);
		}
	}
	
	return 0;
}

ISR(TIMER0_COMPA_vect) {

}

ISR(TIMER0_COMPB_vect) {

}