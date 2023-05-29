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
#include "config.h"
#include "support.h"
#include "dma_driver.h"

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
    volatile int result;

    /* Init platform specific hardware */
    platform_init();

    printf(RED "Ready to start running "TESTID" compiled at "__TIME__":\n");
    printf(YELLOW "\t- Start measuring "BENCHAPP" benchmark\n");
    printf(YELLOW "\t- Start address 0x%.8X\n", (unsigned int)&__text_start);

    dwt_unlock();

    printf(GREEN "\nPress any key to start...\n");
    getchar();
    initialise_benchmark ();
    printf(GREEN "Running...\n");

    while(1)
    {
        #ifdef C0_DMA0
        dma0_start();
        #endif
        #ifdef C0_DMA1
        dma1_start();
        #endif

        for(it = 0; it < N_SAMPLES; it++)
        {
            dwt_enable_counters();
            dwt_reset_cycnt();
            result = benchmark_body(1);
            cycles[it] = dwt_read_cycnt();

            #ifdef C0_STATS
            printf(BLUE "%lu\n", cycles[it]);
            #endif
        }

        #ifdef C0_DMA0
        dma0_ch_disable();
        #endif
        #ifdef C0_DMA1
        dma1_ch_disable();
        #endif

        #ifndef C0_STATS
        print_cycles(cycles);
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
