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
#include "dma_driver.h"
#include "config.h"

#ifdef TPA
#include "tpa.h"
#include "tpa_cfg.h"
#include "log.h"
#endif

uint32_t cycles[N_SAMPLES];

void print_cycles(uint32_t t_cyc[])
{
    for (size_t i = 0; i < N_SAMPLES; i++)
    {
        printf(BLUE"%lu\n", t_cyc[i]);
    }
    return;
}

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
        tpa_prof_init();
        #elif defined(TPA_MECH)
        tpa_mech_init();
        #endif

        for(it = 0; it < N_SAMPLES; it++)
        {
            #ifdef TPA_PROF
            tpa_prof_start();
            #endif
            #ifdef TPA_MECH
            tpa_mech_start();
            #endif

            dwt_enable_counters();
            dwt_reset_cycnt();
            result = benchmark_body(1);
            cycles[it] = dwt_read_cycnt();

            #ifdef C0_STATS
            printf(BLUE "%lu\n", cycles[it]);
            #endif
            #ifdef TPA_PROF
            tpa_prof_stop();
            #endif
            #ifdef TPA_MECH
            tpa_mech_reset();
            #endif
        }
        #ifdef TPA_PROF
        tpa_print_tmg();
        #endif
        #ifdef TPA_MECH
        LOG_PRINT_MBB_LOG();
        LOG_RESET_MBB_LOG();
        #endif
        #ifdef C0_DMA0
        dma0_ch_disable();
        #endif
        #ifdef C0_DMA1
        dma1_ch_disable();
        #endif
        #ifndef C0_STATS
        print_cycles(cycles);
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
