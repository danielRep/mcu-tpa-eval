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
#include "tpa_prof.h"

int main(void)
{
    int it=0;
    extern uint32_t __text_start;
    volatile int result;

    /* Init platform specific hardware */
    platform_init();

    printf(RED "Ready to start running "TESTID" compiled at "__TIME__":\n");
    printf(YELLOW "\t- App: "BENCHAPP" benchmark\n");
    printf(YELLOW "\t- Start address 0x%.8X\n", (unsigned int)&__text_start);

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

        #ifdef TPA_PROF
        tpa_init_prof();
        #else
        #endif

        for(it = 0; it < N_SAMPLES; it++)
        {
            #ifdef TPA_PROF
            tpa_start_prof();
            #else
            #endif
            printf("test\r\n");
            result = benchmark_body(1);
            printf("test\r\n");
            #ifdef TPA_PROF
            tpa_stop_prof();
            #else
            #endif
        }
        printf("test2\r\n");
        #ifdef TPA_PROF
        tpa_print_tmg_ref();
        printf("---------------------------------\r\n");
        tpa_print_tmg_full();
        #endif

        #ifdef C0_DMA0
        dma0_ch_disable();
        #endif
        #ifdef C0_DMA1
        dma1_ch_disable();
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
