#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"
#include "std/util.h"

void terminal_setcolor(uint8_t color);

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

void terminal_clear();

void terminal_putchar(char c);

void terminal_write(const char* data, size_t size);

void terminal_write_noNewline(const char* data, size_t size);

void terminal_writestring(const char* data);

void terminal_initialize(void);

void terminal_crash(const char* data);

void terminal_nextline();

void terminal_scroll();

#endif // TERMINAL_H