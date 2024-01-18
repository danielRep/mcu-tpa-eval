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
#include "cache_drv.h"

#ifdef TPA_MECH
#define CM33
#define TOTAL_HW_BKPTS  8
#include "utpamech.h"
#endif

extern void fill_cache();

#ifdef C1_IC_STATS
uint32_t ch, cm;
#endif

#ifdef C1_IC
static const struct arm_cache_dev_cfg_t SSE_200_CACHE_CFG_S = {
    .base = MUSCA_CPU_ELEMENT_S_BASE};

struct arm_cache_dev_t SSE_200_CACHE_DEV_S = {&(SSE_200_CACHE_CFG_S)};
#endif

int main(void)
{
    /* Init platform specific hardware */
    platform_init();
    printf("Running ifi interf app compiled at "__TIME__"...\n");
#ifdef C1_IC
    arm_cache_full_invalidate(&SSE_200_CACHE_DEV_S);
#endif

#ifdef TPA_MECH
    /* Enable IPI interrupt */
    utpamech_corunner_init();
#endif

    while(1)
    {
#ifdef C1_IC_STATS
    arm_cache_clear_statistic_value(&SSE_200_CACHE_DEV_S);
    arm_cache_statistic_enable(&SSE_200_CACHE_DEV_S);
#endif

    fill_cache();

    printf("Core1 running!\r\n");

#ifdef C1_IC_STATS
    arm_cache_statistic_disable(&SSE_200_CACHE_DEV_S);
    ch = arm_cache_get_hit_count(&SSE_200_CACHE_DEV_S);
    cm = arm_cache_get_miss_count(&SSE_200_CACHE_DEV_S);
    printf(BLUE "ch: %lu\n", ch);
    printf(BLUE "cm: %lu\n", cm);
#endif
    }

    return 0;
}
