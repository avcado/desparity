KERNCFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude
CC := i386-elf-gcc
AS := nasm
LDS := src/linker.ld
BIN := desparity.bin
OBJ := bin/boot.o bin/kernel.o
LDFLAGS := -ffreestanding -O2 -nostdlib

all: multiboot kernel link

# Compiles multiboot stub
multiboot:
	@echo Compiling the multiboot stub! :D
	@mkdir -pv bin
	@$(AS) -felf32 src/boot.asm -o bin/boot.o

# Compiles the kernel
kernel:
	@echo Compiling the kernel! :D
	@mkdir -pv bin/
	@$(CC) -c src/kernel.c -o bin/kernel.o $(KERNCFLAGS)

# Links everything together
link:
	@echo Linking desparity! :D
	@$(CC) -T $(LDS) -o $(BIN) $(LDFLAGS) $(OBJ) -lgcc

# Create the ISO
makeIso:
	mkdir -pv isodir/boot/grub
	cp $(BIN) isodir/boot/$(BIN)
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o desparity.iso isodir

# Clean!
clean:
	rm -rfv bin
	rm desparity.bin desparity.iso
	rm -rfv isodir/
