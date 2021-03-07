#pragma once
#include "typedefs.h"
static inline void outb(uint_16 port, uint_8 val){
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}