// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "drivers/device_drivers.h"
#include "drivers/rtos_scheduler.h"
#include "drivers/wifi.h"
#include "drivers/communication_stack.h"

static void heartbeat_task(void) {
    printf("%s\n", HEARTBEAT_MSG);
}

int main(void) {
    printf("%s\n", INIT_OK_MSG);

    if (!drivers_init()) {
        printf("Drivers init failed\n");
        return 1;
    }

    scheduler_init();
    scheduler_add_task(heartbeat_task, "heartbeat", 1000);

    if (wifi_connect(WIFI_SSID, WIFI_PASS)) {
        // Initialize communication stack and perform HTTP GET
        comms_init();
        if (comms_http_get(HTTP_HOST, HTTP_PORT, HTTP_PATH)) {
            printf("%s\n", HTTP_GET_OK_MSG);
        }
        // Clean up connection
        wifi_disconnect();
    }

    // Simulate a few scheduler ticks
    for (int i = 0; i < 3; ++i) {
        scheduler_tick(1000);
    }

    return 0;
}
