#pragma once
#include "kerror.h"
#include "libc/stdio.h"
#include "libc/string.h"

// Define the GDT Struct
struct gdt_entry {
  uint16_t limitLow;
  uint16_t baseLow;
  uint8_t baseMedium;
  union {
    uint8_t nullDesc;
  };
  union {
    uint8_t access;
    struct {
      uint8_t accesed:1;
      uint8_t rw_bit:1;
      uint8_t dir:1;
      uint8_t exec:1;
      uint8_t type:1;
      uint8_t priv:2;
      uint8_t present:1;
    };
  };
  uint8_t limitHigh:4;
  union {
    uint8_t flags:4;
    struct {
      uint8_t resv:2;
      uint8_t size:1;
      uint8_t granularity:1;
    };
  };
  uint8_t baseHigh;
};

struct gdt_entry gdt;

// Setup desired limit
void desiredLimit() {
    uint64_t desired_limit;

    gdt.limitLow = desired_limit&0xFFFF;
    gdt.limitHigh = (desired_limit>>16)&0x0F;
    
    // Setup null descriptor.
    memset(&gdt.nullDesc,0,sizeof(struct gdt_entry));
    printf("Desired limit for GDT setup!\n");
}