#pragma once


// Define the struct of GDT
struct GDT {
    int base;
    int limit;
    int type;
};