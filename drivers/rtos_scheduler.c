// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#include "drivers/rtos_scheduler.h"
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 8

typedef struct {
    task_fn_t fn;
    char name[24];
    uint32_t period_ms;
    uint32_t elapsed_ms;
    uint8_t active;
} task_t;

static task_t tasks[MAX_TASKS];

void scheduler_init(void) {
    memset(tasks, 0, sizeof(tasks));
    printf("Scheduler initialized\n");
}

int scheduler_add_task(task_fn_t fn, const char *name, uint32_t period_ms) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        if (!tasks[i].active) {
            tasks[i].fn = fn;
            strncpy(tasks[i].name, name ? name : "task", sizeof(tasks[i].name)-1);
            tasks[i].period_ms = period_ms;
            tasks[i].elapsed_ms = 0;
            tasks[i].active = 1;
            printf("Task added: %s (%u ms)\n", tasks[i].name, period_ms);
            return i;
        }
    }
    printf("Task add failed: no slots\n");
    return -1;
}

void scheduler_tick(uint32_t elapsed_ms) {
    for (int i = 0; i < MAX_TASKS; ++i) {
        if (tasks[i].active) {
            if (tasks[i].elapsed_ms + elapsed_ms >= tasks[i].period_ms) {
                tasks[i].elapsed_ms = 0;
                tasks[i].fn();
            } else {
                tasks[i].elapsed_ms += elapsed_ms;
            }
        }
    }
}

void scheduler_run_due(void) {
    // In this simple scheduler, tick triggers tasks immediately
}
