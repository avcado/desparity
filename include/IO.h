#pragma once
#include "typedefs.h"

#ifndef OUTB
#define OUTB

void outb(uint_16 port, uint_8 val){
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

#endif //OUTB