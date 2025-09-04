#ifndef TIMER_H
#define TIMER_H
#include "std/util.h"
#include "std/stdio.h"
#include <stdint.h>
#include "idt/idt.h"

uint32_t ticks;

void initTimer();
void onIrq0(struct InterruptRegisters *regs);

#endif // TIMER_H