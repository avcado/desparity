#pragma once
#include "libc/stdio.h"
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

// Init function so i can run it in init()
void initIDT() {
    remapPIC();
    printf("Remapped PIC!\n");
}