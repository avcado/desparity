KERNCFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra
CC := i386-elf-gcc
AS := nasm
LDS := linker.ld
BIN := desparity.bin
OBJ := boot.o kernel.o

# Compiles multiboot sstub
multiboot:
	mkdir -pv bin
	$(AS) -felf32 boot.asm -o bin/boot.o

# Compiles the kernel
kernel:
	mkdir -pv bin/
	$(CC) -c kernel.c -o bin/kernel.o $(KERNCFLAGS)

# Links everything together
link:
	$(CC) -T $(LDS) -o $(BIN) $(CFLAGS) 
