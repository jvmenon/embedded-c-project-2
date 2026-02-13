// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef RAM_ENTITY_H
#define RAM_ENTITY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool ram_init(void);
bool ram_write(uint32_t addr, const void *data, size_t len);
bool ram_read(uint32_t addr, void *data, size_t len);

#endif // RAM_ENTITY_H
