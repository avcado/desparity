#include <stdio.h>
#include "kerror.h"
#include "init.h"

void main(void){
  terminal_initialize();
  printf("Despairty build 0\nStarting init system.\n");
  init();
}