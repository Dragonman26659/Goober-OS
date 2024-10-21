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

    // Initialise Core
    initGdt();
    initIdt();
    initTimer();

    // Initialise Basic Modules
    CommandInit();

    // Initialise base drivers
    InitKeyboard(CommandType);

    // Setup scheduler
    int pwr = 1;

    // Main Loop of OS
    while (pwr > 0) {
        UpdateTerminal();
    }
}