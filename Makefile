KERNCFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude -Iinclude/libc
CC := i386-elf-gcc
AS := nasm
LDS := src/linker.ld
BIN := desparity.bin
OTHEROBJ := bin/boot.o bin/kernel.o
OBJ := bin/irq.o bin/idt.o bin/irqHandle.o
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
	@$(AS) -felf32 include/idt.asm -o bin/irq.o
	# C kernel stuff
	@$(CC) -c src/kernel.c -o bin/kernel.o $(KERNCFLAGS)
	@$(CC) -c src/irq_handle.c -o bin/irqHandle.o $(KERNCFLAGS)
	@$(CC) -c src/idt.c -o bin/idt.o $(KERNCFLAGS)

# Links everything together
link:
	@echo Linking desparity! :D
	# THANK YOU XLATB_PT2!!!:D
	@$(CC) -T src/linker.ld -c -o bin/kernel.o $(OBJ) -lgcc -nostdlib
	@echo passed.
	$(CC) -T src/linker.ld -o desparity.bin $(OTHEROBJ) -lgcc -nostdlib
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