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

#ifdef TPA_MECH
#define CM33
#define TOTAL_HW_BKPTS  8
#include "utpamech.h"
#endif

extern void fill_cache();

int main(void)
{
    /* Init platform specific hardware */
    platform_init();
    printf("Running ifi interf app compiled at "__TIME__"...\n");

#ifdef TPA_MECH
    /* Enable IPI interrupt */
    utpamech_corunner_init();
#endif

    while(1)
    {

    fill_cache();

    //printf("Core1 running!\r\n");
    }
    return 0;
}
