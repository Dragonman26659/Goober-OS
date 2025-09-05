#include "timer.h"


const uint32_t freq = 100;
int callbackID = 0;


timerCallback_t timerCallbacks[16] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

// Update ticks on ossilation
void onIrq0(struct InterruptRegisters *regs) {
    ticks++;

    for (int x; x < 17; x++) {
        timerCallback_t tc = timerCallbacks[x];
        tc.cTicks++;

        if (tc.cTicks == tc.ticks) {
            tc.callback();
            tc.cTicks = 0;
        }
    }
}


// Initialise the timer
void initTimer() {
    ticks = 0;
    irq_install_handler(0, &onIrq0);

    // Ossilator - 1.1931816666 MHz
    uint32_t divisor = 1193180/freq;

    // 0011 0110
    outPortB(0x43, 0x36);
    outPortB(0x40, (uint8_t)(divisor & 0xFF));
    outPortB(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}