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
#include "dwt.h"
#include "platform_config.h"
#include "platform_base_addrs.h"
#include "support.h"
#include "config.h"

#if defined (C0_DMA0) || defined (C0_DMA1)
#include "dma_driver.h"
#endif

#ifdef TPA_PROF
#include "profiler.h"
#endif

#ifdef C0_STATS
uint32_t cycles[N_SAMPLES];
#endif

#ifdef TPA_PROF

void DebugMon_Handler(void)
{
    printf(RED "DebugMon_Handler\n");
    //code_mon_debughandler();
}

#endif

int main(void)
{
    int it=0;
    extern uint32_t __text_start;
    extern uint32_t __data_start__;

    volatile int result;

    /* Init platform specific hardware */
    platform_init();

    printf(RED "Ready to start running "TESTID" compiled at "__TIME__".\n");
    printf(YELLOW "\t- Workload: "BENCHAPP" benchmark\n");
    printf(YELLOW "\t- .text start: 0x%.8X\n", (unsigned int)&__text_start);
    printf(YELLOW "\t- .data start: 0x%.8X\n", (unsigned int)&__data_start__);

    printf(GREEN "\nPress any key to start...\n");
    getchar();

    dwt_unlock();
    initialise_benchmark ();

    printf(GREEN "Sampling %dx. Running...\n", N_SAMPLES);

    while(1)
    {
        #ifdef C0_DMA0
        dma0_start();
        #endif
        #ifdef C0_DMA1
        dma1_start();
        #endif
        #ifdef TPA_PROF
        profiler_init();
        #endif

        for(it = 0; it < N_SAMPLES; it++)
        {
            #ifdef C0_STATS
            dwt_enable_counters();
            dwt_reset_cycnt();
            #endif

            result = benchmark_body(1);

            #ifdef C0_STATS
            cycles[it] = dwt_read_cycnt();
            printf(BLUE "%lu\n", cycles[it]);
            #endif
        }

        #ifdef TPA_PROF
        profiler_dump();
        #endif
        #ifdef C0_DMA0
        dma0_ch_disable();
        #endif
        #ifdef C0_DMA1
        dma1_ch_disable();
        #endif
        #ifdef C0_DMA0
        dma0_print_dst();
        #endif
        #ifdef C0_DMA1
        dma1_print_dst();
        #endif

        if(verify_benchmark (result))
        {printf(GREEN BENCHAPP" benchmark run smoothly...\n");}
        else
        {printf(RED BENCHAPP" benchmark exited with errors...\n");}

        printf(YELLOW "Press any key to restart...\n");
        getchar();
    }

    return 0;
}
