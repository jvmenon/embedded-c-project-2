// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "drivers/device_drivers.h"
#include <stdio.h>
#include "wifi.h"
#include "drivers/ram_entity.h"
#include "drivers/application_processor.h"
#include "drivers/memory_manager.h"

bool drivers_init(void) {
    printf("Power regulator: 3.3V rail enabled\n");
    printf("Battery monitor: VBAT OK\n");

    memory_manager_init();

    if (!app_processor_init()) return false;
    if (!ram_init()) return false;

    // Flash (AT25) stub JEDEC ID read
    printf("Flash (AT25): JEDEC ID read -> 0x1F 0x66 0x01 (simulated)\n");

    if (!wifi_init()) return false;

    printf("Device drivers initialized\n");
    return true;
}
