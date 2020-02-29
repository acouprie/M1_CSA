/* M1 CSA, ASN, lab 4.1 */
#include "../at91sam7s.h"

#define DELAY_IN_PULSES 31250
#define LED	0
#define PERIOD 100

int period_pulse = MCK * PERIOD / 1000 / 8;
float period_duration = 0.5;

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

/**
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

void set_cdty(float duration) {
  PWM_CDTY(LED) = period_pulse * duration;
}

void __attribute__ ((interrupt("IRQ"))) handle_pio(void) {
	int v;

	if((PIO_PDSR & PUSH1) == 0) {
    us0_puts("flag");
    period_duration += 0.1;
    set_cdty(period_duration);
	}

	v = PIO_ISR;
	v = AIC_EOICR;
}

int main(void) {
  us0_init();

  // Set the clock
  TC0_CCR = TC_CLKDIS;
  TC0_CMR = TC_TCCLKS_CLOCK3 | TC_CPCTRG;
  TC0_RC = DELAY_IN_PULSES;
  TC0_CCR = TC_SWTRG | TC_CLKEN;

	/* initialization */
  // PWM
  PWM_CMR(LED) = PWM_CPRE_MCK_8 | PWM_CPOL;
  PWM_CPRD(LED) = period_pulse;
  set_cdty(period_duration);
  PWM_ENA = 1 << LED;

  // interrupt button
  AIC_IDCR = 1 << ID_PIO;
  void handle_pio(void);
  AIC_SVR[ID_PIO] = (uint32_t)handle_pio;
  AIC_SMR[ID_PIO] = 0;

  PIO_ODR = PUSH1 | PUSH2;
  PIO_IER = PUSH1 | PUSH2;

  int x = AIC_EOICR;
  AIC_ICCR = 1 << ID_PIO;
  AIC_IECR = 1 << ID_PIO;
  UNMASK_IRQ;

  /* main loop */
	while(1) {
	}

	return 0;
}
