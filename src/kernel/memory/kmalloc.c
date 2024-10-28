#include "kmalloc.h"

// Heap information
static uint32_t heapStart;
static uint32_t heapSize;
static uint32_t threshold;
static bool kmallocInitalised = false;


// Initalise kernal memory allocation to heap
void kmalloc_init(uint32_t intialHeapSize) {
    heapStart = KERNEL_MALLOC;
    heapSize = 0;
    threshold = 0;
    kmallocInitalised = true;

    changeHeapSize(intialHeapSize);
}

void changeHeapSize(int newSize) {
    int oldPageTop = CEIL_DIV(heapSize, 0x1000);
    int newPageTop = CEIL_DIV(newSize, 0x1000);

    int diff = newPageTop = oldPageTop;

    for (int i = 0; i < diff; i++) {
        uint32_t phys = pmmAllocPageFrame();
        memMapPage(KERNEL_MALLOC + oldPageTop * 0x1000 + i * 0x1000, phys, PAGE_FLAG_WRITE);
    }
}