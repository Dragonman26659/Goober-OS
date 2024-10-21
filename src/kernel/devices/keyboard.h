#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../std/util.h"
#include "../std/stdio.h"
#include "../idt/idt.h"
#include <stdint.h>
#include <stdbool.h>


void InitKeyboard();
void keyboardHandler(struct InterruptRegisters *regs);


#endif // KEYBOARD_H