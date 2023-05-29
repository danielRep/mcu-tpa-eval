/*
 * Authors:
 *      Daniel Oliveira <daniel.oliveira@tango-project.org>
 *      Sandro Pinto <sandro.pinto@tango-project.org>
 *
 * contention-eval is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 */

#include "content_eval.h"
#include "platform_config.h"
#include "platform_base_addrs.h"

#define ARRAY_SIZE 2048

int main(void)
{
    static int __attribute__((used)) buffer[ARRAY_SIZE] = {1};
    /* Init platform specific hardware */
    platform_init();
    printf("Hello from core1!\n");

    while(1)
    {
        for (size_t i = 0; i < ARRAY_SIZE; i++)
        {
            buffer[i] = i;
        }
    }

    return 0;
}
