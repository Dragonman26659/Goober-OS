
sudo apt-get install nasm qemu

# Install build dependencies
sudo apt-get install bison flex libgmp3-dev libmpfr-dev libmpc-dev

# Download and build GCC cross-compiler
wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz
tar xzf gcc-12.2.0.tar.gz
cd gcc-12.2.0
./configure --target=i386-elf --prefix=/usr/local/cross --disable-nls --disable-libssp --enable-languages=c
make -j4
sudo make install


i386-elf-gcc --version
i386-elf-ld --version
nasm --version