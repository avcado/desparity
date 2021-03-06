// include/libc includes
#include <stdio.h>

// include/ includes
#include "kerror.h"
#include "init.h"

void main(void){
  // Initialize everything VGA.
  terminal_initialize();
  // Start the init system
  init();
}