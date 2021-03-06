/* GDT */
#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "libc/stdio.h"
#include "libc/string.h"

// GDT Entry
struct gdt_entry {
  uint16_t limitLow;
  uint16_t baseLow;
  uint8_t baseMedium;
  /**** Descriptors ****/
  union {
      uint8_t nullDesc;
  };
  union {
      uint8_t dataDesc;
  };
  union {
      uint8_t codeDesc;
  };
  /**** End Descriptors ****/
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

uint64_t desiredLimit = 0;
struct gdt_entry gdt;

void setupDesiredValues() {
    // Data desc
    memset(&gdt.dataDesc,(1<<44) | (1<<47) | (1<<41),
           sizeof(struct gdt_entry));
    
    // Code desc
    memset(&gdt.codeDesc,(1<<44) | (1<<47) | (1<<41) | (1<<43) | (1<<53),
           sizeof(struct gdt_entry));
    
    // Null desc
    memset(&gdt.nullDesc,0,sizeof(struct gdt_entry));

    // Tell the world we've done it.
    printf("Setup some GDT descriptors' value.\n");
}

void initGDT() {
    // Setup the desired values.
    setupDesiredValues();
}