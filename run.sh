cd /mnt/d/'Goober OS'
export PATH=$PATH:/usr/local/i386elfgcc/bin

# Compile kernel
make
make

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

make clean