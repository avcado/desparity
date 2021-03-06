/* Init system for
 * Desparity.
 * Add functions to init()
 * so they can be run */
#pragma once
#include "gdt.h"

#ifndef INIT
#define INIT

void init() {
    terminal_setcolor(VGA_COLOR_LIGHT_BLUE);
    printf("Despairty build 0\nStarting init system.\n");
    terminal_setcolor(VGA_COLOR_WHITE);
    initGDT();
}

#endif //INIT