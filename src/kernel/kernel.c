// Standard Library
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "include/std/stdio.h"
#include "include/Core/multiboot.h"

// Kernel Core
#include "include/Debug/terminal.h"
#include "include/Core/idt.h"
#include "include/Core/gdt.h"
#include "include/Scheduler/timer.h"
#include "include/memory/memory.h"

// basic devices
#include "include/Debug/keyboard.h"

// Core Programs
#include "include/Debug/commandline.h"



// Toggle to 1 to enable kernel level debug console
#define DEBUG 1







/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif



/* This OS will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "this must be compiled with a ix86-elf compiler"
#endif



void InitCore() {
    // Initialise Core
    initGdt();
    initIdt();
    initTimer();
}

void InitDebug() {
    /* Initialize terminal interface */
	terminal_initialize();


    // Initialise Debug Commands
    CommandInit();

    // Initialise basic keboard support
    InitKeyboard(CommandType);


    // TODO: add debug console to scheduler
}


// Kernel Main File
void kmain(uint32_t magic, struct multiboot_info* bootInfo) {
    uint32_t mod1 = *(uint32_t*)(bootInfo->mods_addr + 4);
    uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~0xFFF;


    // Initalise core systems to be able to use anything
    InitCore();

    #ifdef DEBUG = 1
        InitDebug();
    #endif


    // Scheduler boot
    // TODO: make scheduler
    for (;;) {
        UpdateTerminal();
    }
}