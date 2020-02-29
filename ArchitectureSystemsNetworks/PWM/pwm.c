/*
 * 0.1 / 1 second = P / (MCK / DIV)
 * Pp = Ps * MCK / DIV
 */

#define DELAY 4687

int init_boil() {
    // Set the clock
    TC0_CCR = TC_CLKDIS;
    TC0_CMR = TC_TCCLKS_CLOCK5 | TC_CPCTRG;
    TC0_RC = DELAY;
    TC0_CCR = TC_SWTRG | TC_CLKEN;
}

int set_boil() {

}

int main() {
  init_boil();
}
