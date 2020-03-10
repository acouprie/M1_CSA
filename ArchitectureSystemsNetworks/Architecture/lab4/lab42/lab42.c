/* M1 CSA, ASN, lab 4.2 */
#include "../at91sam7s.h"

#define LED			0
#define THM			1
#define THM_MIN		-100
#define THM_MAX		1500
#define THM_REF		500
#define BOILER		1
#define PERIOD 100

int period_pulse = MCK * PERIOD / 1000 / 8;

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


int main(void) {
  /* initialization */
  us0_init();
  int temp, error, n = 0, is_on = 0, press = 0;
  float p;

  ADC_MR = ADC_PRESCAL(0x3f);
  ADC_CHER = 1 << THM;
	ADC_IER = ADC_EOC(THM);

  PIO_PER = GREEN | YELLOW | PUSH1;
  PIO_ODR = PUSH1;
  PIO_OER = YELLOW | GREEN;
  PIO_SODR = YELLOW | GREEN;

  PWM_CMR(BOILER) = PWM_CPRE_MCK_8 | PWM_CPOL;
  PWM_CPRD(BOILER) = period_pulse;
  PWM_CDTY(BOILER) = 0;
  PWM_ENA = 1 << BOILER;

	/* main loop */
	while(1) {
    ADC_CR = ADC_START;
    while(!(ADC_SR & ADC_EOC(THM)));
    temp = ADC_CDR[1];

    if(!press && ((PIO_PDSR & PUSH1) == 0)) {
      press = !press;
    } else if (press && ((PIO_PDSR & PUSH1) != 0)) {
      press = !press;
      is_on = !is_on;
      if (is_on) {
        us0_puts("Start machine");
      } else {
        us0_puts("Machine stop");
        PIO_SODR = YELLOW | GREEN;
        PWM_CDTY(BOILER) = 0;
      }
    }

    if(is_on) {
      error = THM_REF - temp;
      p = 1024 * error / 16;

      if(temp < THM_REF) {
        PIO_CODR = YELLOW;
        PIO_SODR = GREEN;
        PWM_CDTY(BOILER) = p;
      } else {
        PIO_SODR = YELLOW;
        PIO_CODR = GREEN;
        PWM_CDTY(BOILER) = 0;
      }
    }

	}
	return 0;
}
