/* Function to be able
 * to print out error
 * messages */
#pragma once

#include "vga.h"
#include <libc/stdio.h>

void kerror(const char* error){
    printf("Uncaught error: ");
    // Set the color
    terminal_setcolor(VGA_COLOR_LIGHT_RED);
    // Print
    printf(error);
    // Reset the color
    terminal_setcolor(VGA_COLOR_WHITE);
}