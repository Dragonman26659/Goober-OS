// Standard Library
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "std/stdio.h"
#include "multiboot.h"

// Kernel Core
#include "terminal.h"
#include "idt/idt.h"
#include "gdt/gdt.h"
#include "timer.h"
#include "memory/memory.h"
#include "scheduler/scheduler.h"

// basic devices
#include "devices/keyboard.h"

// Core Programs
#include "command/commandline.h"



/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif



/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "this must be compiled with a ix86-elf compiler"
#endif



// Kernel Main File
void kmain(uint32_t magic, struct multiboot_info* bootInfo) {
	/* Initialize terminal interface */
	terminal_initialize();

    uint32_t mod1 = *(uint32_t*)(bootInfo->mods_addr + 4);
    uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~0xFFF;


    // Initialise Core
    initGdt();
    initIdt();
    initTimer();

    // Initialise Basic Modules
    CommandInit();

    // Initialise base drivers
    InitKeyboard(CommandType);

    // Main Loop of OS
    for (;;) {
        schedule();
        UpdateTerminal();
    }
}