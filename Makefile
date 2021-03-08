KERNCFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude -Iinclude/libc
CC := i386-elf-gcc
AS := nasm
LDS := src/linker.ld
BIN := desparity.bin
OTHEROBJ := bin/boot.o bin/kernel.o
OBJ := bin/idt.o
LDFLAGS := -ffreestanding -O2 -nostdlib
QEMU := qemu-system-x86_64
QEMUFLAGS := -cdrom

all: multiboot kernel link makeIso qemu clean

# Compiles multiboot stub
multiboot:
	@echo Compiling the multiboot stub! :D
	@mkdir -pv bin
	@$(AS) -felf32 src/boot.asm -o bin/boot.o

# Compiles the kernel
kernel:
	@echo Compiling the kernel! :D
	@mkdir -pv bin/
	# ASM kernel stuff
	@$(AS) -felf32 include/idt.asm -o bin/idt.o
	@echo Should have compiled THE THing
	# C kernel stuff
	@$(CC) -c src/kernel.c -o bin/kernel.o $(KERNCFLAGS)

# Links everything together
link:
	@echo Linking desparity! :D
	# THANK YOU XLATB_PT2!!!:D
	@$(CC) -o bin/kernel.o -T src/linker.ld -c $(OBJ) -lgcc -nostdlib
	@echo passed.
	$(CC) -o desparity.bin -T src/linker.ld $(OTHEROBJ) -lgcc -nostdlib
	@echo passed.

# Create the ISO
makeIso:
	mkdir -pv isodir/boot/grub
	cp $(BIN) isodir/boot/$(BIN)
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o desparity.iso isodir

# Clean!
clean:
	rm -rfv bin || true
	rm desparity.bin desparity.iso || true
	rm -rfv isodir/ || true

qemu:
	$(QEMU) $(QEMUFLAGS) desparity.iso