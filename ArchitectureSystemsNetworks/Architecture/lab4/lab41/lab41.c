/* M1 CSA, ASN, lab 4.1 */
#include "../at91sam7s.h"

#define DELAY_IN_PULSES 31250
#define LED	0
#define PERIOD 100

int period_pulse = MCK * PERIOD / 1000 / 8;
int press1 = 0, press2 = 0;
float period_duration = 1.0f;

/**
 * Synchronously write a character to US0.
 * @param c	Written character.
 */
void us0_putc(char c) {
	while(!(US0_CSR && US_TXRDY));
	US0_THR = c;
}

/**
 * Synchronously write a string to US0.
 * @param s		Written string.
 */
void us0_puts(char *s) {
	while(*s)
		us0_putc(*s++);
}

/*
 * Initialize US0 (57,500 bauds, no parity, 8-bit character, 1 stop bit).
 */
void us0_init(void) {
	US0_CR = US_TXEN;
	US0_MR = US_USCLKS_MCK
		   | US_CHRL_8
		   | US_PAR_NONE
		   | US_NBSTOP_1
		   | US_CHMODE_NORMAL;
	US0_BRGR = MCK / 57600 / 16;
	US0_TTGR = 10;
}

int main(void) {
  us0_init();

	/* initialization */
  // PWM
  PWM_CMR(LED) = PWM_CPRE_MCK_8 | PWM_CPOL;
  PWM_CPRD(LED) = period_pulse;
  PWM_CDTY(LED) = period_pulse * period_duration;
  PWM_ENA = 1 << LED;

  PIO_PER = PUSH1 | PUSH2;
  PIO_ODR = PUSH1 | PUSH2;
  PIO_IER = PUSH1 | PUSH2;

  /* main loop */
	while(1) {
    if(!press1 && ((PIO_PDSR & PUSH1) == 0)) {
      press1 = !press1;
      if(period_duration < 1)
        period_duration += 0.1f;
      PWM_CDTY(LED) = period_pulse * period_duration;
  	} else if (press1 && (PIO_PDSR & PUSH1) != 0) {
      press1 = !press1;
    }

    if(!press2 && ((PIO_PDSR & PUSH2) == 0)) {
      press2 = !press2;
      if (period_duration > 0)
        period_duration -= 0.1f;
      PWM_CDTY(LED) = period_pulse * period_duration;
  	} else if (press2 && (PIO_PDSR & PUSH2) != 0) {
      press2 = !press2;
    }
	}

	return 0;
}
