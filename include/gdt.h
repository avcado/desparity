#pragma once
#include "kerror.h"
#include "libc/stdio.h"
#include "libc/string.h"
extern void gdt_flush(unsigned int);

// GDT Entry
struct gdt_entry_struct {
   uint_16 limit_low; // The lower 16 bits of the limit.
   uint_16 base_low; // The lower 16 bits of the base.
   uint_8 base_middle; // The next 8 bits of the base.
   uint_8 access; // Access flags, determine what ring this segment can be used in.
   uint_8 granularity; // Granularity
   uint_8 base_high; // The last 8 bits of the base.
} __attribute__((packed));

// Create a type
typedef struct gdt_entry_struct gdt_entry_t;

// GDT Pointer Struct
struct gdt_ptr_struct {
   uint16_t limit; // The upper 16 bits of all selector limits.
   uint32_t base; // The address of the first gdt_entry_t struct.
} __attribute__((packed));

// Make a type out of it
typedef struct gdt_ptr_struct gdt_ptr_t; 

// Function prototypes and variables
extern void gdt_flush(u32int);

// Internal function prototypes.
static void init_gdt();
static void gdt_set_gate(s32int,u32int,u32int,u8int,u8int);

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;

// Initialize the GDT
void initGDT() {
  gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
  gdt_ptr.base  = (uint32_t)&gdt_entries;

  gdt_set_gate(0, 0, 0, 0, 0); // Null segment
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
  gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
  gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

  // Flush the gdt.
  gdt_flush((uint32_t)&gdt_ptr);
}
