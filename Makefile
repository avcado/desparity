KERNCFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra
CC := i386-elf-gcc
AS := nasm
LDS := linker.ld
BIN := desparity.bin
OBJ := bin/boot.o bin/kernel.o
LDFLAGS := -ffreestanding -O2 -nostdlib

# Compiles multiboot sstub
multiboot:
	@echo Compiling the multiboot sutb! :D
	@mkdir -pv bin
	@$(AS) -felf32 boot.asm -o bin/boot.o

# Compiles the kernel
kernel:
	@echo Compiling the kernel! :D
	@mkdir -pv bin/
	@$(CC) -c kernel.c -o bin/kernel.o $(KERNCFLAGS)

# Links everything together
link:
	@echo Linking desparity! :D
	@$(CC) -T $(LDS) -o $(BIN) $(LDFLAGS) $(OBJ) -lgcc
