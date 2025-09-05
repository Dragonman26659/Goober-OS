#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "include/Debug/vga.h"
#include "include/std/util.h"

void terminal_setcolor(uint8_t color);

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

void terminal_clear();

void terminal_putchar(char c);

void terminal_write(const char* data, size_t size);

void terminal_writestring_Y(const char* data, int screeny);
void terminal_writestring_XY(const char* data, int screenx, int screeny);

void terminal_write_noNewline(const char* data, size_t size);

void terminal_writestring(const char* data);

void terminal_initialize(void);

void terminal_crash(const char* data);

void terminal_nextline();

void terminal_scroll();

void terminal_writestring_pos(const char* data, int screenx, int screeny);

void terminal_clearline(size_t line);



// Cursor
void terminal_setcursorpos(int row, int col);
void terminal_disable_cursor();

#endif // TERMINAL_H