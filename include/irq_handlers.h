#pragma once
#include "IO.h"


void irq0_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq1_handler() {
	outb(0x20, 0x20); //EOI
}
 
void irq2_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq3_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq4_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq5_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq6_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq7_handler() {
    outb(0x20, 0x20); //EOI
}
 
void irq8_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI          
}
 
void irq9_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq10_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq11_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq12_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq13_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq14_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void irq15_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}