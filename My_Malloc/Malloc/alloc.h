#ifndef MALLOC_ALLOC_H
#define MALLOC_ALLOC_H

#include <stddef.h> //size_t

void* malloc(size_t size);
void free(void* ptr);
void* realloc(void* ptr, size_t size);
void* calloc(size_t nelem, size_t elsize);

#endif //MALLOC_ALLOC_H
