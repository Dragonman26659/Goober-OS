#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CEIL_DIV(a, b) (((a + b) - 1)/b)
#define ROUND_UP(x, y) (((x) + (y) - 1) / (y))

struct InterruptRegisters{
    uint32_t cr2;
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, csm, eflags, useresp, ss;
};


// Memory
int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);

// String
size_t strlen(const char*);
int strcmp(const char *s1, const char *s2);

// Ports
void outPortB(uint16_t port, uint8_t value);
char inPortB(uint16_t port);


#endif // UTIL_H