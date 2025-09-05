#ifndef STDIO_H
#define STDIO_H
#include "util.h"
#include "Include/debug/terminal.h"
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#define EOF (-1)

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);
void putc(char c);

#endif // STDIO_H