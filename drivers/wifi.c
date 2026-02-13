// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "wifi.h"
#include <stdio.h>
#include <string.h>
#include "config.h"

static bool connected = false;
static bool tcp_opened = false;

bool wifi_init(void) {
    printf("WiFi driver init (ESP8266 AT over UART)\n");
    printf("AT -> OK\n");
    printf("AT+CWMODE=1 -> OK\n");
    return true;
}

bool wifi_connect(const char *ssid, const char *pass) {
    printf("AT+CWJAP=\"%s\",\"%s\" -> CONNECT\n", ssid, pass);
    connected = true;
    printf("%s\n", WIFI_CONNECTED_MSG);
    return true;
}

bool wifi_tcp_open(const char *host, int port) {
    if (!connected) return false;
    printf("AT+CIPSTART=\"TCP\",\"%s\",%d -> CONNECT\n", host, port);
    tcp_opened = true;
    return true;
}

bool wifi_tcp_send(const char *data, size_t len) {
    if (!tcp_opened) return false;
    printf("AT+CIPSEND=%zu -> ", len);
    printf("SEND OK\n");
    // Print a truncated view of data for trace
    size_t preview = len < 60 ? len : 60;
    printf("TX: %.*s\n", (int)preview, data);
    return true;
}

int wifi_tcp_receive(char *buf, size_t maxlen) {
    if (!tcp_opened) return -1;
    const char *resp = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
    size_t n = strlen(resp);
    if (n > maxlen) n = maxlen;
    memcpy(buf, resp, n);
    printf("RX: %.*s\n", (int)n, buf);
    return (int)n;
}

void wifi_disconnect(void) {
    if (tcp_opened) {
        printf("AT+CIPCLOSE -> CLOSED\n");
        tcp_opened = false;
    }
    if (connected) {
        connected = false;
        printf("%s\n", WIFI_DISCONNECTED_MSG);
    }
}
