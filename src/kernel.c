#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"

void kernel_main(void){
  // Initialize VGA
  terminal_initialize();
}
