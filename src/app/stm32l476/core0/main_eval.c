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
#include "stm32l476xx.h"
#include "dwt.h"
#include "platform_config.h"
#include "platform_base_addrs.h"
#include "support.h"
#include "config.h"
#include "dma_driver.h"

uint32_t cycles[N_SAMPLES];

#ifdef C0_DMA0
void Interrupt11_Handler(void);
volatile uint32_t total_transfers1 = 0;
void Interrupt11_Handler(void)
{
    if(DMA1->ISR & DMA_ISR_TCIF1)
    {
        DMA1->IFCR |= DMA_IFCR_CTCIF1 | DMA_IFCR_CHTIF1;
        total_transfers1++;
        dma1_restart();
    }
}
#endif

#ifdef C0_DMA1
void Interrupt56_Handler(void);
volatile uint32_t total_transfers2 = 0;
void Interrupt56_Handler(void)
{
    if(DMA2->ISR & DMA_ISR_TCIF1)
    {
        DMA2->IFCR |= DMA_IFCR_CTCIF1 | DMA_IFCR_CHTIF1;
        total_transfers2++;
        dma2_restart();
    }
}
#endif

void print_cycles(uint32_t t_cyc[])
{
    for (size_t i = 0; i < N_SAMPLES; i++)
    {
        printf(BLUE"%lu\n", t_cyc[i]);
    }
    return;
}
extern uint32_t __Vectors;

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

    initialise_benchmark ();
    dwt_unlock();
    printf(GREEN "Running...\n");
    #ifdef C0_ICDC
    printf(GREEN "Warming up caches...\n");
    warm_caches (WARMUP_HEAT);
    #endif

    printf(GREEN "Sampling %dx. Running...\n", N_SAMPLES);

    while(1)
    {
        for(it = 0; it < N_SAMPLES; it++)
        {
            #ifdef C0_DMA0
            dma1_start();
            #endif
            #ifdef C0_DMA1
            dma2_start();
            #endif
            dwt_enable_counters();
            dwt_reset_cycnt();
            result = benchmark_body(1);
            cycles[it] = dwt_read_cycnt();

            #ifdef C0_STATS
            printf(BLUE "%lu\n", cycles[it]);
            #endif

            #ifdef C0_DMA0
            dma1_reinit();
            #endif
            #ifdef C0_DMA1
            dma2_reinit();
            #endif
        }
        #ifndef C0_STATS
        print_cycles(cycles);
        #endif
        #ifdef C0_DMA0
        dma1_print_copy(total_transfers1);
        #endif
        #ifdef C0_DMA1
        dma2_print_copy(total_transfers2);
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
