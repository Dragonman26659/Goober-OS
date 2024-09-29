// Standard Library
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "std/stdio.h"

// Kernel Core
#include "terminal.h"
#include "idt/idt.h"
#include "gdt/gdt.h"
#include "timer.h"


// basic devices
#include "devices/keyboard.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "this must be compiled with a ix86-elf compiler"
#endif

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

    // Initialise Core
    initGdt();
    initIdt();
    initTimer();

    printf("Initilised core kernel!");
    printf("Loading basic peripheral devices");

    // Setup command line

    // Initialise keyboard (with reference to command line char handler)
    InitKeyboard();

    // Initalise scheduler

    for (;;) {}
}