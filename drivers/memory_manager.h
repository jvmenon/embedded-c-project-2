// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>
#include <stdbool.h>

void memory_manager_init(void);
void *mm_alloc(size_t size);
void mm_free(void *ptr);
size_t mm_available(void);

#endif // MEMORY_MANAGER_H
