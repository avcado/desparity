/* Function to be able
 * to print out error
 * messages */
#pragma once

#include "vga.h"
#include <libc/stdio.h>

void kerror(const char* error){
    printcol(VGA_COLOR_RED, "Uncaught error: ");
    printf(error);
    // Halt the processor
    printcol(VGA_COLOR_LIGHT_RED, "\nOS has been halted");
    asm("hlt");
}