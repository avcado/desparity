#pragma once
#include "kerror.h"

// Define the GDT Struct
struct gdt_entry {
  uint16_t limitLow;
  uint16_t baseLow;
  uint8_t baseMedium;
  uint8_t access;
  uint8_t limit:4;
  uint8_t flags:4;
  uint8_t baseHigh;
};