#include "../vga.h"


#ifndef PRINTF
#define PRINTF

// A extremely basic printf
// It doesn't support %s, %d, etc.

void printf(const char* data){
    terminal_write(data, strlen(data));
}

#endif //PRINTF