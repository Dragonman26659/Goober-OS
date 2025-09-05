#ifndef TIMER_H
#define TIMER_H
#include "Include/std/util.h"
#include "Include/std/stdio.h"
#include <stdint.h>
#include "include/Core/idt.h"

uint32_t ticks;

void initTimer();
void onIrq0(struct InterruptRegisters *regs);

#endif // TIMER_H