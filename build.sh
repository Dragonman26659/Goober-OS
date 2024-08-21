#!/bin/bash
cd /mnt/d/'Goober OS'
make && qemu-system-i386 -fda build/main_floppy.img