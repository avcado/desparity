// Statuses (OK, FAILED)
#pragma once

#include "vga.h"

#ifndef OKSTATUS
#define OKSTATUS

void okStatus(const char* message){
    // Set the color to green
    terminal_colorWrite(VGA_COLOR_LIGHT_GREEN, "[OK] ");
    // Reset the color to white (default)
    terminal_color = VGA_COLOR_WHITE;
    // Now we'll print out the message
    terminal_writestring(message);
}

#endif //OKSTATUS

#ifndef FAILEDSTATUS
#define FAILEDSTATUS

void failedStatus(const char* message){
    // Set the color to light red
    // We set it to light red so they can actually see it.
    terminal_colorWrite(VGA_COLOR_LIGHT_RED, "[FAILED] ");
    // Reset the color to white (default)
    terminal_color = VGA_COLOR_WHITE;
    // Now we'll print out the message
    terminal_writestring(message);
}

#endif //FAILEDSTATUS