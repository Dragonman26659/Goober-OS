#ifndef KMALLOC_H
#define KMALLOC_h

#include "../std/util.h"
#include "stdint.h"
#include "stdbool.h"
#include "memory.h"


// Kmalloc initalisation
void kmalloc_init(uint32_t intialHeapSize);

// Change the heap size
void changeHeapSize(int newSize);

// Kernel Level Malloc
uint32_t* kMalloc(size_t size);

// Free a pointer
void kFree(void* ptr);

#endif //KMALLOC_H