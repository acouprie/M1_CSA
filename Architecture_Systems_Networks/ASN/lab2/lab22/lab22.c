/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s.h"

#define DELAY_IN_PULSES 62500
int i, s = 0;

void __attribute__ ((interrupt("IRQ"))) handle_pio(void) {
    int v;
    if(s)
        PIO_CODR = YELLOW;
    else
        PIO_SODR = YELLOW;
    s=!s;
    v = TC0_SR;
    v = AIC_EOICR;
}

int main(void) {
    /* initialization */
    AIC_IDCR = 1 << ID_TC0;
    void handle_pio(void);
    AIC_SVR[ID_TC0] = (uint32_t)handle_pio;
    AIC_SMR[ID_TC0] = 0;

    TC0_CCR = TC_CLKDIS;
    TC0_CMR = TC_TCCLKS_CLOCK3 | TC_CPCTRG;
    TC0_RC = DELAY_IN_PULSES;
    TC0_CCR = TC_SWTRG | TC_CLKEN;
    PIO_PER = YELLOW;
    PIO_OER = YELLOW;
    TC0_IER = TC_CPCS;

    int x = AIC_EOICR;
    AIC_ICCR = 1 << ID_TC0;
    AIC_IECR = 1 << ID_TC0;
    UNMASK_IRQ;

    /* main loop */
    while(1) {

    }

    return 0;
}
