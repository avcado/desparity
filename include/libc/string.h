// String stuff
#pragma once
#include <stddef.h>

#ifndef MEMSET
#define MEMSET

// memset sets memory.
void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (size_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}

#endif //MEMSET