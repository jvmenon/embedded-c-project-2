// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "drivers/ram_entity.h"
#include <stdio.h>
#include <string.h>

#define SRAM_SIZE (64 * 1024)
static unsigned char sram[SRAM_SIZE];

bool ram_init(void) {
    memset(sram, 0xFF, sizeof(sram));
    printf("External SRAM initialized (simulated SPI)\n");
    return true;
}

bool ram_write(uint32_t addr, const void *data, size_t len) {
    if (addr + len > SRAM_SIZE) return false;
    memcpy(&sram[addr], data, len);
    printf("SRAM write: addr=%u len=%zu\n", addr, len);
    return true;
}

bool ram_read(uint32_t addr, void *data, size_t len) {
    if (addr + len > SRAM_SIZE) return false;
    memcpy(data, &sram[addr], len);
    printf("SRAM read: addr=%u len=%zu\n", addr, len);
    return true;
}
