#include "main.h"
#include "dac.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

#define RESOLUTION 200

uint8_t sintable[RESOLUTION]; //sin 8bit
// uint16_t sintable[RESOLUTION]; //sin 12bit

int main() {
	dac_init();

	//sin 8bit
	/*uint8_t i;

	for(i = 0;i < RESOLUTION;i++) {
		sintable[i] = 0xFF & (uint8_t)round((sin(M_PI*2/RESOLUTION*i)+1)*0x7F);
	}
	
	for(;;) {
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
		dac8(((t*7&t>>3)|(~t*t)&t>>9)&t*3>>13);
		_delay_us(100);
	}*/

	//triangle 8bit
	/*uint8_t i;

	for(;;) {
		for(i = 0;i < 0xFF;i++) {
			dac8(i);
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

	//triangle 12bit
	/*uint16_t i;

	for(;;) {
		for(i = 0;i < 0xFFF;i++) {
			dac12(i);
		}
	}*/
	
	return 0;

}