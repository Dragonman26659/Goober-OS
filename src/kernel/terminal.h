#ifndef TERMINAL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"

size_t strlen(const char* str);

void terminal_setcolor(uint8_t color);

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

void terminal_clear();

void terminal_putchar(char c);

void terminal_write(const char* data, size_t size);

void terminal_writestring(const char* data);

void terminal_initialize(void);

#endif // TERMINAL_H