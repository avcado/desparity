#pragma once

// Paging variables,
/*
 * page_directory
 * page_table
*/

#ifndef PAGE_VARS
#define PAGE_VARS

unsigned long *page_directory = (unsigned long *)0x9C000;
unsigned long *page_table = (unsigned long *)0x9D000;

#endif //PAGE_VARS

// Fill up the tables
#ifndef FILL_TABLE
#define FILL_TABLE

void fillTable() {
    unsigned long address = 0; // Phyiscal address where page will be
    for (unsigned int i; i<1024; i++){
        page_table[i] = address | 3;
        address = address + 4096; // 4kb
    }
}

#endif //FILL_TABLE

// Fill up the paging directory
#ifndef PAGE_DIR
#define PAGE_DIR

void fillPageDir() {
    // Fill the first entry
    page_directory[0] = page_table; // attribute set to: supervisor level, read/write, present(011 in binary)
    page_directory[0] = page_directory[0] | 3;
    // Fill the rest
}

#endif //PAGE_DIR