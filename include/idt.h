#pragma once
#include "libc/stdio.h"
#include "irq_handlers.h"
#include "IO.h"

struct IDTEntry {
    unsigned short int offsetLower; // offset lower bits
    unsigned short int selector;
    uint_8 zero;
    uint_8 typeAttrib;
    unsigned short int offsetHigher; // offset higher bits
};

struct IDTEntry IDT[256];

// Remap the PIC (Programmable Interrupt Controller)
// using outb
void remapPIC() {
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 40);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
}

// External functions we'll call in assembly
extern int load_idt();
extern int irq0();
extern int irq1();
extern int irq2();
extern int irq3();
extern int irq4();
extern int irq5();
extern int irq6();
extern int irq7();
extern int irq8();
extern int irq9();
extern int irq10();
extern int irq11();
extern int irq12();
extern int irq13();
extern int irq14();
extern int irq15();

// Some variables for addresses
unsigned long irq0Addr;
unsigned long irq1Addr;
unsigned long irq2Addr;
unsigned long irq3Addr;          
unsigned long irq4Addr; 
unsigned long irq5Addr;
unsigned long irq6Addr;
unsigned long irq7Addr;
unsigned long irq8Addr;
unsigned long irq9Addr;          
unsigned long irq10Addr;
unsigned long irq11Addr;
unsigned long irq12Addr;
unsigned long irq13Addr;
unsigned long irq14Addr;          
unsigned long irq15Addr;         
unsigned long idtAddr;
unsigned long idt_ptr[2];


// IRQ Addressing
// NOTE: This code is disgusting and I do not want to waste
// any more resources on this.
void IRQAddress() {
    irq0Addr = (unsigned long)irq0; 
	IDT[32].offsetLower = irq0Addr & 0xffff;
	IDT[32].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET
	IDT[32].zero = 0;
	IDT[32].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[32].offsetHigher = (irq0Addr & 0xffff0000) >> 16;
 
	irq1Addr = (unsigned long)irq1; 
	IDT[33].offsetLower = irq1Addr & 0xffff;
	IDT[33].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[33].zero = 0;
	IDT[33].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[33].offsetHigher = (irq1Addr & 0xffff0000) >> 16;
 
	irq2Addr = (unsigned long)irq2; 
	IDT[34].offsetLower = irq2Addr & 0xffff;
	IDT[34].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[34].zero = 0;
	IDT[34].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[34].offsetHigher = (irq2Addr & 0xffff0000) >> 16;
 
	irq3Addr = (unsigned long)irq3; 
	IDT[35].offsetLower = irq3Addr & 0xffff;
	IDT[35].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[35].zero = 0;
	IDT[35].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[35].offsetHigher = (irq3Addr & 0xffff0000) >> 16;
 
	irq4Addr = (unsigned long)irq4; 
	IDT[36].offsetLower = irq4Addr & 0xffff;
	IDT[36].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[36].zero = 0;
	IDT[36].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[36].offsetHigher = (irq4Addr & 0xffff0000) >> 16;
 
	irq5Addr = (unsigned long)irq5; 
	IDT[37].offsetLower = irq5Addr & 0xffff;
	IDT[37].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[37].zero = 0;
	IDT[37].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[37].offsetHigher = (irq5Addr & 0xffff0000) >> 16;
 
	irq6Addr = (unsigned long)irq6; 
	IDT[38].offsetLower = irq6Addr & 0xffff;
	IDT[38].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[38].zero = 0;
	IDT[38].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[38].offsetHigher = (irq6Addr & 0xffff0000) >> 16;
 
	irq7Addr = (unsigned long)irq7; 
	IDT[39].offsetLower = irq7Addr & 0xffff;
	IDT[39].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[39].zero = 0;
	IDT[39].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[39].offsetHigher = (irq7Addr & 0xffff0000) >> 16;
 
	irq8Addr = (unsigned long)irq8; 
	IDT[40].offsetLower = irq8Addr & 0xffff;
	IDT[40].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[40].zero = 0;
	IDT[40].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[40].offsetHigher = (irq8Addr & 0xffff0000) >> 16;
 
	irq9Addr = (unsigned long)irq9; 
	IDT[41].offsetLower = irq9Addr & 0xffff;
	IDT[41].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[41].zero = 0;
	IDT[41].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[41].offsetHigher = (irq9Addr & 0xffff0000) >> 16;
 
	irq10Addr = (unsigned long)irq10; 
	IDT[42].offsetLower = irq10Addr & 0xffff;
	IDT[42].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[42].zero = 0;
	IDT[42].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[42].offsetHigher = (irq10Addr & 0xffff0000) >> 16;
 
	irq11Addr = (unsigned long)irq11; 
	IDT[43].offsetLower = irq11Addr & 0xffff;
	IDT[43].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[43].zero = 0;
	IDT[43].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[43].offsetHigher = (irq11Addr & 0xffff0000) >> 16;
 
	irq12Addr = (unsigned long)irq12; 
	IDT[44].offsetLower = irq12Addr & 0xffff;
	IDT[44].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[44].zero = 0;
	IDT[44].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[44].offsetHigher = (irq12Addr & 0xffff0000) >> 16;
 
	irq13Addr = (unsigned long)irq13; 
	IDT[45].offsetLower = irq13Addr & 0xffff;
	IDT[45].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[45].zero = 0;
	IDT[45].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[45].offsetHigher = (irq13Addr & 0xffff0000) >> 16;
 
	irq14Addr = (unsigned long)irq14; 
	IDT[46].offsetLower = irq14Addr & 0xffff;
	IDT[46].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[46].zero = 0;
	IDT[46].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[46].offsetHigher = (irq14Addr & 0xffff0000) >> 16;
 
    irq15Addr = (unsigned long)irq15; 
	IDT[47].offsetLower = irq15Addr & 0xffff;
	IDT[47].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET  
	IDT[47].zero = 0;
	IDT[47].typeAttrib = 0x8e; // INTERRUPT_GATE  
	IDT[47].offsetHigher = (irq15Addr & 0xffff0000) >> 16;
 
	// fill the IDT descriptor  
	idtAddr = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDTEntry) * 256) + ((idtAddr & 0xffff) << 16);
	idt_ptr[1] = idtAddr >> 16 ;
}

// Init function so i can run it in init()
void initIDT() {
    remapPIC();
    printf("Remapped PIC!\n");
    IRQAddress();
    printf("Addressed IRQs\n");
}