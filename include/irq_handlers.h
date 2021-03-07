#pragma once
#include "IO.h"


static inline void irq0void_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq1_handler() {
	outb(0x20, 0x20); //EOI
}
 
static inline void irq2_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq3_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq4_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq5_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq6_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq7_handler() {
    outb(0x20, 0x20); //EOI
}
 
static inline void irq8_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI          
}
 
static inline void irq9_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq10_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq11_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq12_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq13_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq14_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}
 
static inline void irq15_handler() {
    outb(0xA0, 0x20);
    outb(0x20, 0x20); //EOI
}