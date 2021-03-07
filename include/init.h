/* Init system for
 * Desparity.
 * Add functions to init()
 * so they can be run */
#pragma once
#include "gdt.h"
#include "idt.h"
#include "libc/stdio.h"
#include "vga.h"

#ifndef INIT
#define INIT

void init();

#endif //INIT

#ifndef TESTCOL
#define TESTCOL

// Tests color to make sure that colors
// are working.  This is also ugly code
void testColors();

#endif //TESTCOL