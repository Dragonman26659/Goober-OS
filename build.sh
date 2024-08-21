# Build and launch the OS
cd /mnt/d/'Goober OS'
make
qemu-system-x86_64 -drive format=raw,file="build/OS.bin",index=0,if=floppy,  -m 128M