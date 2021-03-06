#pragma once
#include "kerror.h"
#include "libc/stdio.h"
#include "libc/string.h"
extern void gdt_flush(unsigned int);

// GDT Entry
struct gdt_entry_struct
{
   uint_16 limit_low;           // The lower 16 bits of the limit.
   uint_16 base_low;            // The lower 16 bits of the base.
   uint_8 base_middle;         // The next 8 bits of the base.
   uint_8 access;              // Access flags, determine what ring this segment can be used in.
   uint_8 granularity;         // Granularity
   uint_8 base_high;           // The last 8 bits of the base.
} __attribute__((packed));

// Create a type
typedef struct gdt_entry_struct gdt_entry_t;