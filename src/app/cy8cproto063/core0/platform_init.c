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
#include "platform_base_addrs.h"
#include "platform_config.h"
#include "dma_driver.h"

bool uart_init(void)
{
    return true;
}

void pins_init(void)
{
    return;
}

void systemclock_config(void)
{
    return;
}

int _read(int file, char *ptr, int len)
{
    int n_chars = 0;
    uint8_t byte;

    if(ptr != NULL)
    {
        for(n_chars = 0; n_chars < len; ++ptr)
        {
            //while ((USART0->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK) == 0U);
            //USART_ReadBlocking(USART0, &byte, 1);
            *ptr = (char)byte;
            ++n_chars;

            if((*ptr == '\n') || (*ptr == '\r'))
            {
                break;
            }
        }
    }
    return (n_chars);
}

int _write(int file, const uint8_t *ptr, int len)
{
    if (isatty(file)) {
        for (size_t i = 0; i < len; i++)
        {
            //while (0U == (USART0->STAT & USART_STAT_TXIDLE_MASK));
            //USART_WriteBlocking(USART0, &ptr[i], 1);
        }

        return len;

    }
    return -1;
}

int platform_init(void)
{
#if C0_CLK_MAX
    systemclock_config();
#endif

    if(!(uart_init()))
    {
        return -1;
    }

    pins_init();

    printf(CLEAR);
    printf(RED "System clock configured: %ld.\n", SystemCoreClock);

#ifdef MULTICORE
    printf(RED "Core1 setup and running "INTRFAPP" interf app.\n");
    printf(YELLOW "\t- VTOR: %.8X\n", 0xDEADBEEF);
#endif

#ifdef FPM
    printf(RED "Flash Performance mode configured.\n");
    printf(YELLOW "\t- accelerator 0xDEADBEEF\n");
    printf(YELLOW "\t- prefetcher 0xDEADBEEF\n");
#else
    //SYSCON->FMCCR &= ~(SYSCON_FMCCR_FETCHCFG_MASK | SYSCON_FMCCR_DATACFG_MASK | SYSCON_FMCCR_ACCEL_MASK | SYSCON_FMCCR_PREFEN_MASK);
#endif

#ifdef C0_DMA0
    dma0_init();
#endif

#ifdef C0_DMA1
    dma1_init();
#endif

    return 0;
}
