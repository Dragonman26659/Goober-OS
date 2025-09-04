#ifndef MEMORY_H
#define MEMORY_H

#include "stdint.h"
#include "stdbool.h"
#include "../multiboot.h"
#include "../std/stdio.h"
#include "../std/util.h"

// Kernel memory info
#define KERNEL_START 0xC0000000
#define KERNEL_MALLOC 0xD0000000

// Page Flags
#define PAGE_SIZE 4096
#define PAGE_FLAG_PRESENT (1 << 0)
#define PAGE_FLAG_WRITE (1 << 1)
#define PAGE_FLAG_OWNER (1 << 9)



#endif // MEMORY_H