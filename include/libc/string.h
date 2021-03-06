// String stuff
#pragma once
#include <stddef.h>


/******* Memory functions *******/

#ifndef MEMSET
#define MEMSET

// memset sets memory to a location
void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (size_t i = 0; i < size; i++){
		buf[i] = (unsigned char) value;
    }
	return bufptr;
}

#endif //MEMSET

#ifndef MEMMOVE
#define MEMMOVE

// memmove moves memory.
void* memmove(void* destptr, const void* srcptr, size_t size) {
    unsigned char* dest = (unsigned char*) destptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	if (dest < src) {
		for (size_t i = 0; i < size; i++)
			dest[i] = src[i];
	} else {
		for (size_t i = size; i != 0; i--)
			dest[i-1] = src[i-1];
	}
	return destptr;
}

#endif //MEMMOVE