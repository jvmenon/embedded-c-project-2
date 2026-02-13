// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "drivers/communication_stack.h"
#include <stdio.h>
#include <string.h>
#include "wifi.h"
#include "config.h"

bool comms_init(void) {
    printf("Communication stack initialized\n");
    return true;
}

bool comms_http_get(const char *host, int port, const char *path) {
    if (!wifi_tcp_open(host, port)) return false;
    char req[256];
    snprintf(req, sizeof(req),
             "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             path, host);
    if (!wifi_tcp_send(req, strlen(req))) return false;
    char buf[256];
    int n = wifi_tcp_receive(buf, sizeof(buf));
    if (n > 0) {
        printf("%s\n", HTTP_GET_OK_MSG);
        return true;
    }
    return false;
}
