cd /mnt/d/'Goober OS'
export PATH=$PATH:/usr/local/i386elfgcc/bin

#Compile
i386-elf-as src/boot.s -o bin/boot.o

i386-elf-gcc -ffreestanding -c src/kernel/kernel.c -o bin/kernel.o -std=gnu99  -O2 -Wall -Wextra


#link
i386-elf-ld -T src/linker.ld -o bin/myos.bin -O2 -nostdlib bin/boot.o bin/kernel.o

# Generate ISO
if grub-file --is-x86-multiboot bin/myos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

mkdir -p isodir/boot/grub
cp bin/myos.bin isodir/boot/myos.bin
cp src/grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o isodir/myos.iso isodir


qemu-system-i386 -cdrom isodir/myos.iso