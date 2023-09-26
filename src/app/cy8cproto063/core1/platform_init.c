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

bool uart_init(void)
{
    return true;
}

void pins_init(void)
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
            //while ((USART2->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK) == 0U);
            //USART_ReadBlocking(USART2, &byte, 1);
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
            //while (0U == (USART2->STAT & USART_STAT_TXIDLE_MASK));
            //USART_WriteBlocking(USART2, &ptr[i], 1);
        }

        return len;

    }
    return -1;
}

int platform_init(void)
{
    if(!(uart_init()))
        return -1;

    pins_init();

    printf(CLEARSCREEN);

    return 0;
}
