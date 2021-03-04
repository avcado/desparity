#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"
#include "statuses.h"

void kernel_main(void){
  // Initialize VGA
  terminal_initialize();
  terminal_writestring("my os\n");
  okStatus("POGGERS!\n");
  failedStatus("NOT POGGERS!\n");
}
