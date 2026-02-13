// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef WIFI_H
#define WIFI_H

#include <stdbool.h>
#include <stddef.h>

bool wifi_init(void);
bool wifi_connect(const char *ssid, const char *pass);
bool wifi_tcp_open(const char *host, int port);
bool wifi_tcp_send(const char *data, size_t len);
int  wifi_tcp_receive(char *buf, size_t maxlen);
void wifi_disconnect(void);

#endif // WIFI_H
