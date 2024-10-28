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

#define NUM_PAGES_DIRS 256
#define NUM_PAGE_FRAMES (0x100000000 / 0x1000 / 8)

#define REC_PAGEDIR ((uint32_t*)0xFFFFF000)
#define REC_PAGETABLE(i) ((uint32_t*) (0xFFC00000 + ((i) << 12)))


// Page Directory
extern uint32_t initial_page_dir[1024];



void initMemory(uint32_t memHigh, uint32_t physicalAllocStart);
void invalidate(uint32_t VirtAddr);

void pmm_init(uint32_t memLow, uint32_t memHigh);
uint32_t pmmAllocPageFrame();
void memMapPage(uint32_t virtualAddr, uint32_t physAddr, uint32_t flags);
void syncPageDirs();
uint32_t* memGetCurrentPageDir();
void memChangePageDir(uint32_t* pd);


#endif // MEMORY_H