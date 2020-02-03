/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s.h"
#define DELAY_IN_PULSES 62500

int main(void) {
    /* initialization */
    int i, s = 0;
    TC0_CCR = TC_CLKDIS;
    TC0_CMR = TC_TCCLKS_CLOCK3 | TC_CPCTRG;
    TC0_RC = DELAY_IN_PULSES;
    TC0_CCR = TC_SWTRG | TC_CLKEN;
    PIO_PER = YELLOW;
    PIO_OER = YELLOW;

    /* main loop */
    while(1) {
        if(TC0_SR & TC_CPCS) {
            if(s)
                PIO_CODR = YELLOW;
            else
                PIO_SODR = YELLOW;
            s=!s;
        }
    }

    return 0;
}
