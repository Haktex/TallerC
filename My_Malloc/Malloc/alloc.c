#include "alloc.h"
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define META_SIZE sizeof(struct block_meta)
void* head = NULL;

struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
};

struct block_meta* find_free_block(struct block_meta** last, size_t size) {
    struct block_meta* current = head;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

static struct block_meta* request_space(struct block_meta* last, size_t size) {
    struct block_meta* block;
    block = sbrk(0);
    void* request = sbrk(size + META_SIZE);
    assert((void*)block == request);

    if (request == (void*) -1)
        return NULL;

    if (last)
        last->next = block;

    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}

void* malloc(size_t size) {
    struct block_meta* block;

    if (size <= 0)
        return NULL;

    if (!head) {
        block = request_space(NULL, size);
        if (!block)
            return NULL;

        head = block;
    } else {
        struct block_meta* last = head;
        block = find_free_block(&last, size);
        if (!block) {
            block = request_space(last, size);
            if (!block)
                return NULL;

        } else
            block->free = 0;
    }
    return(block+1);
}

static struct block_meta* get_block_ptr(void* ptr) {
    return (struct block_meta*)ptr - 1;
}

void free(void* ptr) {
    if (!ptr)
        return;

    struct block_meta* block_ptr = get_block_ptr(ptr);
    assert(block_ptr->free == 0);
    block_ptr->free = 1;
}

void* realloc(void *ptr, size_t size) {
    if (!ptr)
        return malloc(size);

    struct block_meta* block_ptr = get_block_ptr(ptr);
    if (block_ptr->size >= size)
        return ptr;

    void* new_ptr;
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;

    memcpy(new_ptr, ptr, block_ptr->size);
    free(ptr);
    return new_ptr;
}

void* calloc(size_t nelem, size_t elsize) {
    size_t size = nelem * elsize;
    void* ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}