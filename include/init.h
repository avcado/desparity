/* Init system for
 * Desparity.
 * Add functions to init()
 * so they can be run */
#pragma once
#include "gdt.h"
#include "libc/stdio.h"
#include "vga.h"

#ifndef INIT
#define INIT

void init() {
    printf("Testing the 16 colors\n\n");
    testColors();
    printf("\n"); // pet peeve.
    terminal_setcolor(VGA_COLOR_LIGHT_BLUE);
    printf("Starting init system.\n");
    terminal_setcolor(VGA_COLOR_WHITE);
    initGDT();
}

#endif //INIT

#ifndef TESTCOL
#define TESTCOL

// Tests color to make sure that colors
// are working
void testColors() {
    printcol(VGA_COLOR_BLUE, "blue ");
    printcol(VGA_COLOR_GREEN, "green ");
    printcol(VGA_COLOR_CYAN, "cyan ");
    printcol(VGA_COLOR_RED, "red ");
    printcol(VGA_COLOR_MAGENTA, "magenta ");
    printcol(VGA_COLOR_BROWN, "brown ");
    printcol(VGA_COLOR_LIGHT_GREY, "light grey ");
    printcol(VGA_COLOR_DARK_GREY, "dark grey ");
    printcol(VGA_COLOR_LIGHT_BLUE, "light blue ");
    printcol(VGA_COLOR_LIGHT_GREEN, "light green   ");
    printcol(VGA_COLOR_LIGHT_CYAN, "light cyan ");
    printcol(VGA_COLOR_LIGHT_RED, "light red ");
    printcol(VGA_COLOR_LIGHT_MAGENTA, "light magenta ");
    printcol(VGA_COLOR_LIGHT_BROWN, "light brown ");
    printcol(VGA_COLOR_WHITE, "white\n");
}

#endif //TESTCOL