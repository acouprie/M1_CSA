/* M1 CSA, ASN, lab 3.2 */
#include "../at91sam7s.h"

#define DELAY_IN_PULSES 31250
#define THM	0

int v;
int n = 0;
char str[16];

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
 * @param s Written string.
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

void __attribute__ ((interrupt("IRQ"))) handle_tc0(void) {
  ADC_CR = ADC_START;
  v = TC0_SR;
  v = AIC_EOICR;
}

void __attribute__ ((interrupt("IRQ"))) handle_adc(void) {
  while(!(ADC_SR & ADC_EOC(THM)));
  v = ADC_CDR0 * 100 / 1023;
  sprintf(str, "%d \n\r", v);
  us0_puts(str);
  v = ADC_SR;
  v = AIC_EOICR;
}

int main(void) {
  us0_init();

  ADC_MR = ADC_PRESCAL(0x3f);
  ADC_CHER = 1 << THM;

  // Set the clock
  TC0_CCR = TC_CLKDIS;
  TC0_CMR = TC_TCCLKS_CLOCK3 | TC_CPCTRG;
  TC0_RC = DELAY_IN_PULSES;
  TC0_CCR = TC_SWTRG | TC_CLKEN;

  /* initialization */
  ADC_IER = ADC_EOC(THM);
  AIC_IDCR = 1 << ID_ADC;
  AIC_SVR[ID_ADC] = (uint32_t)handle_adc;
  AIC_SMR[ID_ADC] = 0;

  AIC_SVR[ID_TC0] = (uint32_t)handle_tc0;
  AIC_SMR[ID_TC0] = 0;
  TC0_IER = TC_CPCS;

  int x = AIC_EOICR;
  AIC_ICCR = (1 << ID_ADC) | (1 << ID_TC0);
  AIC_IECR = (1 << ID_ADC) | (1 << ID_TC0);
  UNMASK_IRQ;

  /* main loop */
  while(1) {

  }

  return 0;
}
