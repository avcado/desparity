/* Init system for
 * Desparity.
 * Add functions to init()
 * so they can be run */
#pragma once
#include "gdt.h"
#include "idt.h"
#include "irq_handlers.h"
#include "libc/stdio.h"
#include "vga.h"

void init() {
    printf("Color test: ");
    testColors();
    printcol(VGA_COLOR_LIGHT_BLUE, "\nStarting init system...\n");
    initGDT();
    initIDT();
}

void testColors(){
    printcol(VGA_COLOR_BLUE, "blue ");
    printcol(VGA_COLOR_GREEN, "green ");
    printcol(VGA_COLOR_CYAN, "cyan ");
    printcol(VGA_COLOR_RED, "red ");
    printcol(VGA_COLOR_MAGENTA, "magenta ");
    printcol(VGA_COLOR_BROWN, "brown ");
    printcol(VGA_COLOR_LIGHT_GREY, "light grey ");
    printcol(VGA_COLOR_DARK_GREY, "dark grey ");
    printcol(VGA_COLOR_LIGHT_BLUE, "light blue   ");
    printcol(VGA_COLOR_LIGHT_GREEN, "light green ");
    printcol(VGA_COLOR_LIGHT_CYAN, "light cyan ");
    printcol(VGA_COLOR_LIGHT_RED, "light red ");
    printcol(VGA_COLOR_LIGHT_MAGENTA, "light magenta ");
    printcol(VGA_COLOR_LIGHT_BROWN, "light brown ");
    printcol(VGA_COLOR_WHITE, "white\n");
}