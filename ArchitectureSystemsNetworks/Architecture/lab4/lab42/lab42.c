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
  int temp, n = 0;
  char str[8];

  ADC_MR = ADC_PRESCAL(0x3f);
  ADC_CHER = 1 << THM;
	ADC_IER = ADC_EOC(THM);

  PWM_CMR(BOILER) = PWM_CPRE_MCK_8 | PWM_CPOL;
  PWM_CPRD(BOILER) = period_pulse;
  PWM_CDTY(BOILER) = 0;
  PWM_ENA = 1 << BOILER;

	/* main loop */
	while(1) {
    ADC_CR = ADC_START;
    while(!(ADC_SR & ADC_EOC(THM)));
    temp = ADC_CDR[1];

    if(temp < THM_REF) {
      PWM_CDTY(BOILER) = period_pulse;
    } else {
      PWM_CDTY(BOILER) = 0;
    }

    sprintf(str, "%d", temp / 10);
    us0_puts(str);
    while(n < 1000000)
      n++;
    n = 0;
	}
	
	return 0;
}
