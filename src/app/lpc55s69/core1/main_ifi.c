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

extern void fill_cache();

int main(void)
{
    /* Init platform specific hardware */
    platform_init();
    printf("Hello from core1!\n");

    while(1)
    {
#ifdef C1_STATS

#endif

    fill_cache();
#ifdef C1_STATS

#endif

    }

    return 0;
}
