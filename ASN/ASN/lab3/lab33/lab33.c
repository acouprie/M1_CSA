/* M1 CSA, ASN, lab 3.3 */
#include "../at91sam7s.h"

#define THM	0

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
	
	/* main loop */
	while(1) {
		
	}
	
	return 0;
}
