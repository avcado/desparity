#pragma once
#include "../vga.h"
#include "../typedefs.h"

// Function definitions
void printf(const char* data);
void printc(const char* data, size_t size);
void printcol(uint8_t color, const char* data);

#ifndef PRINTF
#define PRINTF

// A extremely basic printf
// It doesn't support %s, %d, etc.

void printf(const char* data){
    printc(data, strlen(data));
}

#endif //PRINTF

#ifndef PRINTC
#define PRINTC

// Print out a character
// to the screen
void printc(const char* data, size_t size){
  for (size_t i = 0; i < size; i++)
    terminal_putchar(data[i]);
}

#endif //PRINTC

#ifndef PRINTH
#define PRINTH

char htocOut[128];
// Print a string but hex
const char* htoc(int value){
  int valPtr = &value;
  uint_8* ptr;
  uint_8 temp;
  uint_8 size = (sizeof(const char**)) * 2 - 1;
  uint_8 i;
  for (i = 0; i < size; i++){
    ptr = ((uint_8*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    htocOut[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    htocOut[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  htocOut[size + 1] = 0;
  return htocOut;
}

void printh(int hex){
    // :)
    printf("0x");
    printf(htoc(hex));
}

#endif //PRINTH

#ifndef PRINTCOL
#define PRINTCOL

void printcol(uint8_t color, const char* data){
  // First we want to set the color
  terminal_setcolor(color);
  // Then we want to print out the data
  printf(data);
  // Finally we can reset the color
  terminal_setcolor(VGA_COLOR_WHITE);
}

#endif //PRINTCOL