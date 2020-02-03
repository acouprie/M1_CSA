/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s.h"

int main(void) {
	
	/* initialization */
	PIO_PER = YELLOW | GREEN | PUSH1 | PUSH2;
	PIO_OER = YELLOW | GREEN;
	PIO_ODR = PUSH1 | PUSH2;
	PIO_SODR = YELLOW | GREEN;
	int green_on = 0;
	int p1 = 0;

	/* main loop */
	while(1) {
		if((PIO_PDSR & PUSH1) == 0) {
			PIO_CODR = YELLOW;
		} else {
			PIO_SODR = YELLOW;
		}

		if(!p1 && (PIO_PDSR & PUSH2) == 0 && green_on == 0) {
			p1 = 1;
			green_on = 1;
			PIO_CODR = GREEN;
		} else if (p1 && (PIO_PDSR & PUSH2) != 0) {
			p1 = 0;
		} else if (!p1 && (PIO_PDSR & PUSH2) == 0 && green_on == 1) {
			green_on = 0;
			PIO_SODR = GREEN;
			p1 = 1;
		} else if (p1 && (PIO_PDSR & PUSH2) != 0) {
			p1 = 0;
		}
	}
	
	return 0;
}
