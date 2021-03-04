#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"

void kernel_main(void){
  terminal_initialize();
  terminal_setcolor(VGA_COLOR_GREEN);
  terminal_writestring("Greenj\n");
}
