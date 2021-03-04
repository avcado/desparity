#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "libc/stdio.h"

void kernel_main(void){
  // Initialize VGA
  terminal_initialize();
  printf("Testing printf in libc\n");
}
