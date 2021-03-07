#pragma once
#include "IO.h"
// Function prototype
extern void _irq0_handler(void);
extern void _irq1_handler(void);
extern void _irq2_handler(void);
extern void _irq3_handler(void);
extern void _irq4_handler(void);
extern void _irq5_handler(void);
extern void _irq6_handler(void);
extern void _irq7_handler(void);
extern void _irq8_handler(void);
extern void _irq9_handler(void);
extern void _irq10_handler(void);
extern void _irq11_handler(void);
extern void _irq12_handler(void);
extern void _irq13_handler(void);
extern void _irq14_handler(void);
extern void _irq15_handler(void);

// Function declarations
void _irq0_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq1_handler(void) {
	outb(0x20, 0x20); //EOI
}
 
void _irq2_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq3_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq4_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq5_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq6_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq7_handler(void) {
    outb(0x20, 0x20); //EOI
}
 
void _irq8_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI          
}
 
void _irq9_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq10_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq11_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq12_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq13_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq14_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
void _irq15_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}