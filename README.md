# Desparity, An x86 OS

## Based Off Of....
Desparity is based off of OSDev Wiki's Bare Bones. Please do NOT go into the issues and write a 7,000 word essay on why using Bare Bones is bad.

## Compiling

Desparity does not come with a cross-compiler, so you're going to need to compile it first, before compiling.
```sh
# Setup variables
$ export PREFIX="/usr/local/i386-elf"
$ export TARGET=i386-elf
$ export PATH="$PREFIX/bin:$PATH"
# Setup directories
$ mkdir /tmp/src
$ mkdir -v {gcc-build,binutils-build}
# Compile!
# BinUtils
$ curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz
$ tar xf binutils-2.35.1.tar.gz
$ cd binutils-build
$ ../binutils-2.35.1/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
$ sudo make all install 2>&1 | tee configure.log
$ cd ..
# GCC
$ curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz
$ tar xf gcc-10.2.0.tar.gz
$ cd gcc-build
$ ../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c++ --without-headers
$ sudo make all-gcc
$ sudo make all-target-libgcc
$ sudo make install-gcc
$ sudo make install-target-libgcc
```

Once you've setup everything above, add PATH to your shellrc, then restart your shell.\
Clone the repo, and type
```sh
$ make
```
