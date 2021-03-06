#include <stdio.h>

void main(void){
  // Initialize VGA
  terminal_initialize();
  printf("Printf.\n");
  printc("T", 1);
  printc("\n", 1);
  const char* test1 = "This is a test string for htoc";
  const char* test = htoc(&test1);
  printh(test);
}