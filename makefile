CC = i386-elf-gcc
AS = i386-elf-as
LD = i386-elf-ld

CFLAGS = -ffreestanding -O2 -Wall -Wextra -std=gnu99
LDFLAGS = -O2 -nostdlib

OBJ = $(shell ls bin/*.o)

all: src bin/myos.bin

src: 
	make -C src all ; cp src/kernel/*.o bin; cp src/kernel/*/*.o bin; make -C src clean

bin/myos.bin: bin/*.o
	$(LD) $(LDFLAGS) -T src/linker.ld -o $@ $^

clean:
	rm -f bin/*.o bin/myos.bin

.PHONY: src
.PHONY: all clean
