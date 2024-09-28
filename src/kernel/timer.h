#ifndef TIMER_H
#define TIMER_H
#include "util.h"
#include <stdint.h>
#include "idt.h"
#include "stdio.h"


void initTimer();
void onIrq0(struct InterruptRegisters *regs);



#endif // TIMER_H