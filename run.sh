cd /mnt/d/'Goober OS'
export PATH=$PATH:/usr/local/i386elfgcc/bin

# Compile kernel
make
make bin/kernel

# Check if file is multiboot
if grub-file --is-x86-multiboot bin/kernel; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi


# Make ISO
mkdir -p isodir/boot/grub
cp bin/kernel isodir/boot/kernel
cp src/grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o isodir/GooberOS.iso isodir


qemu-system-i386 -cdrom isodir/GooberOS.iso

make clean