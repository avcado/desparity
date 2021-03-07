#include "kerror.h"

void kerror(const char* error){
    printcol(VGA_COLOR_RED, "Uncaught error: ");
    printf(error);
    // Halt the processor
    printcol(VGA_COLOR_LIGHT_RED, "\nOS has been halted");
    asm("hlt");
}