// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef RTOS_SCHEDULER_H
#define RTOS_SCHEDULER_H

#include <stddef.h>
#include <stdint.h>

typedef void (*task_fn_t)(void);

void scheduler_init(void);
int scheduler_add_task(task_fn_t fn, const char *name, uint32_t period_ms);
void scheduler_tick(uint32_t elapsed_ms);
void scheduler_run_due(void);

#endif // RTOS_SCHEDULER_H
