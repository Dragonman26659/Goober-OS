# Define variables for paths and commands
PATH := $(PATH):/usr/local/i386elfgcc/bin
NASM := nasm
CC := i386-elf-gcc
LD := i386-elf-ld

# Default target
all: build/OS.bin

# Build bootloader
build/boot.bin: src/bootloader/boot.asm
	$(NASM) $< -f bin -o $@

# Build kernel entry
build/kernel_entry.o: src/kernel/kernel_entry.asm
	$(NASM) $< -f elf -o $@

# Compile main.c
build/kernel.o: src/kernel/main.c
	$(CC) -ffreestanding -m32 -g -c $< -o $@

# Build zeroes.bin
build/zeroes.bin: src/zeroes.asm
	$(NASM) $< -f bin -o $@

# Link kernel objects
build/full_kernel.bin: build/kernel_entry.o build/kernel.o
	$(LD) -o $@ -Ttext 0x1000 $^ --oformat binary

# Concatenate binaries
build/OS.bin: build/boot.bin build/full_kernel.bin build/zeroes.bin
	cat $^ > $@

.PHONY: all