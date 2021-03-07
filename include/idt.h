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
int load_idt();
int irq0();
int irq1();
int irq2();
int irq3();
int irq4();
int irq5();
int irq6();
int irq7();
int irq8();
int irq9();
int irq10();
int irq11();
int irq12();
int irq13();
int irq14();
int irq15();

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


void IRQAddress();
void initIDT();