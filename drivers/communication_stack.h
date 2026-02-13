// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef COMMUNICATION_STACK_H
#define COMMUNICATION_STACK_H

#include <stdbool.h>

bool comms_init(void);
bool comms_http_get(const char *host, int port, const char *path);

#endif // COMMUNICATION_STACK_H
