#pragma once
#include "kerror.h"

// Define the struct of GDT
struct GDT {
    int base;
    int limit;
    int type;
};