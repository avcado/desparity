/* GDT */
#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "libc/stdio.h"
#include "libc/string.h"

extern void reloadRegs();

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
  union {
    uint8_t rodataDesc;
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

  // Rodata descriptor
  gdt.limitLow = 0xFFFF;
  gdt.limitHigh = 0xFF;
  gdt.baseHigh = 0;
  gdt.baseLow = 0;
  gdt.baseMedium = 0;


  // Tell the world we've done it.
  printf("Setup some GDT descriptors' value.\n");
    
  // Set flags
  gdt.rw_bit = 1;
  gdt.type = 1;
  gdt.exec = 1;  

  printf("GDT Flags setup!\n");

  // kerror("Triple Fault! Check cpudump.");
  asm("mov 0x08, %ax");
  asm("mov %ds, %ax");

  printcol(VGA_COLOR_LIGHT_GREEN, "GDT has been setup!\n");
  // reloadRegs();
}

void initGDT() {
    // Setup the desired values.
    setupDesiredValues();
}
