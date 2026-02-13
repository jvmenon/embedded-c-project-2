// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "drivers/memory_manager.h"
#include <stdio.h>
#include <string.h>
#include "config.h"

// Simple fixed-block memory pool for deterministic behavior
static unsigned char pool[MEM_POOL_BLOCK_SIZE * MEM_POOL_BLOCK_COUNT];
static unsigned char used[MEM_POOL_BLOCK_COUNT];

void memory_manager_init(void) {
    memset(used, 0, sizeof(used));
    printf("Memory manager initialized: %d blocks of %d bytes\n", MEM_POOL_BLOCK_COUNT, MEM_POOL_BLOCK_SIZE);
}

void *mm_alloc(size_t size) {
    if (size > MEM_POOL_BLOCK_SIZE) return NULL;
    for (size_t i = 0; i < MEM_POOL_BLOCK_COUNT; ++i) {
        if (!used[i]) {
            used[i] = 1;
            printf("mm_alloc: block %zu allocated (%zu bytes)\n", i, size);
            return &pool[i * MEM_POOL_BLOCK_SIZE];
        }
    }
    printf("mm_alloc: no blocks available\n");
    return NULL;
}

void mm_free(void *ptr) {
    if (!ptr) return;
    size_t offset = (unsigned char*)ptr - pool;
    size_t index = offset / MEM_POOL_BLOCK_SIZE;
    if (index < MEM_POOL_BLOCK_COUNT && used[index]) {
        used[index] = 0;
        printf("mm_free: block %zu freed\n", index);
    }
}

size_t mm_available(void) {
    size_t count = 0;
    for (size_t i = 0; i < MEM_POOL_BLOCK_COUNT; ++i) if (!used[i]) ++count;
    return count * MEM_POOL_BLOCK_SIZE;
}
