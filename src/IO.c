#include "typedefs.h"
#include "IO.h"

void outb(uint_16 port, uint_8 val){
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}