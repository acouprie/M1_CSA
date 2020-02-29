/* M1 CSA, ASN, lab 1.3 */
#include "../at91sam7s.h"
int p1 = 0;
int green_on = 0;

void __attribute__ ((interrupt("IRQ"))) handle_pio(void) {
	int v;

	// interrupt processing
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
	v = PIO_ISR;
	v = AIC_EOICR;
}


int main(void) {

    /* initialization */
    AIC_IDCR = 1 << ID_PIO;
    void handle_pio(void);
    AIC_SVR[ID_PIO] = (uint32_t)handle_pio;
    AIC_SMR[ID_PIO] = 0;

    PIO_PER = YELLOW | GREEN | PUSH1 | PUSH2;
    PIO_OER = YELLOW | GREEN;
    PIO_ODR = PUSH1 | PUSH2;
    PIO_SODR = YELLOW | GREEN;
    PIO_IER = PUSH1 | PUSH2;

    int x = AIC_EOICR;
    AIC_ICCR = 1 << ID_PIO;
    AIC_IECR = 1 << ID_PIO;
    UNMASK_IRQ;

	while(1) {
	}

	return 0;
}
