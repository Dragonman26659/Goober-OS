#ifndef TIMER_H
#define TIMER_H
#include "std/util.h"
#include <stdint.h>
#include "idt/idt.h"


void initTimer();
void onIrq0(struct InterruptRegisters *regs);



#endif // TIMER_H