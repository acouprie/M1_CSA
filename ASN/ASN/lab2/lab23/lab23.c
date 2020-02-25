/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s-term.h"

#define DELAY_IN_PULSES 31250
int gameOn = 0, seconds = 0;

void putc(char c) {
    while(!(US0_CSR && US_TXRDY));
    US0_THR = c;
}

void puts(char *s) {
    while(*s)
        putc(*s++);
}

void end_game(int win) {
    gameOn = 0;
    seconds = 0;
    PIO_SODR = YELLOW;

    if(win == 1) {
        puts("WIN! ");
    } else {
        puts("LOOSE :( ");
    }
}

void __attribute__ ((interrupt("IRQ"))) handle_pio(void) {
    int v;

    // Push start button (P1)
    if((PIO_PDSR & PUSH1) == 0) {
        PIO_CODR = YELLOW;
        PIO_SODR = GREEN;
        gameOn = 1;
    }

    // push win button (P2)
    if((PIO_PDSR & PUSH2) == 0) {
        PIO_CODR = GREEN;
        if(gameOn)
            end_game(1);
    } else {
        PIO_SODR = GREEN;
    }

    v = PIO_ISR;
    v = AIC_EOICR;
}

int main(void) {
    // config interrupts
    AIC_IDCR = 1 << ID_PIO;
    void handle_pio(void);
    AIC_SVR[ID_PIO] = (uint32_t)handle_pio;
    AIC_SMR[ID_PIO] = 0;

    // Set the clock
    TC0_CCR = TC_CLKDIS;
    TC0_CMR = TC_TCCLKS_CLOCK4 | TC_CPCTRG;
    TC0_RC = DELAY_IN_PULSES;
    TC0_CCR = TC_SWTRG | TC_CLKEN;

    // set input/output
    PIO_PER = YELLOW | GREEN | PUSH1 | PUSH2;
    PIO_OER = YELLOW | GREEN;
    PIO_ODR = PUSH1 | PUSH2;
    PIO_SODR = YELLOW | GREEN;
    PIO_IER = PUSH1 | PUSH2;

    // Display
    US0_CR = US_TXEN;
    US0_MR = US_USCLKS_MCK
            | US_CHRL_8
            | US_PAR_NONE
            | US_NBSTOP_1
            | US_CHMODE_NORMAL;
    US0_BRGR = MCK / 57600 / 16;
    US0_TTGR = 10;
    puts("READY! ");

    int x = AIC_EOICR;
    AIC_ICCR = 1 << ID_PIO;
    AIC_IECR = 1 << ID_PIO;
    UNMASK_IRQ;

    /* main loop */
    while(1) {
        if(gameOn == 1 && (TC0_SR & TC_CPCS)) {
            ++seconds;
            if(seconds > 4) {
                end_game(0);
            }
        }
    }

    return 0;
}

