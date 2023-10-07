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
#include "system_psoc6.h"

/* Platform BSP Includes*/
#include "cyhal_uart.h"
#include "cycfg_system.h"
#include "cycfg_peripherals.h"

cyhal_uart_t cy_retarget_io_uart_obj;
static char cy_retarget_io_stdout_prev_char = 0;

static inline cy_rslt_t cy_retarget_io_getchar(char *c)
{
    return cyhal_uart_getc(&cy_retarget_io_uart_obj, (uint8_t *)c, 0);
}

static inline cy_rslt_t cy_retarget_io_putchar(char c)
{
    return cyhal_uart_putc(&cy_retarget_io_uart_obj, (uint8_t)c);
}

bool uart_init(void)
{
    const cyhal_uart_cfg_t uart_config =
        {
            .data_bits = 8,
            .stop_bits = 1,
            .parity = CYHAL_UART_PARITY_NONE,
            .rx_buffer = NULL,
            .rx_buffer_size = 0};

    cy_rslt_t result = cyhal_uart_init(&cy_retarget_io_uart_obj, CYBSP_UART_TX, CYBSP_UART_RX, CYBSP_UART_CTS, CYBSP_UART_RTS, NULL,
                                       &uart_config);

    if (result == CY_RSLT_SUCCESS)
    {
        result = cyhal_uart_set_baud(&cy_retarget_io_uart_obj, CY_RETARGET_IO_BAUDRATE, NULL);
    }

    return true;
}

void pins_init(void)
{
    return;
}

void systemclock_config(void)
{
    init_cycfg_system();
    // Do any additional configuration reservations that are needed on all cores.
    reserve_cycfg_system();
    reserve_cycfg_peripherals();
}

int _read(int file, char *ptr, int len)
{
    (void)file;

    int32_t nChars = 0;
    if (ptr != NULL)
    {
        cy_rslt_t rslt;
        do
        {
            rslt = cy_retarget_io_getchar(ptr);
            if (rslt == CY_RSLT_SUCCESS)
            {
                ++nChars;
                if ((*ptr == '\n') || (*ptr == '\r'))
                {
                    break;
                }
                ptr++;
            }
        } while ((rslt == CY_RSLT_SUCCESS) && (nChars < len));
    }

    return (nChars);
}

int _write(int file, const uint8_t *ptr, int len)
{
    int32_t nChars = 0;
    (void)file;
    if (ptr != NULL)
    {
        cy_rslt_t rslt = CY_RSLT_SUCCESS;

        for (; nChars < len; ++nChars)
        {
            if ((*ptr == '\n') && (cy_retarget_io_stdout_prev_char != '\r'))
            {
                rslt = cy_retarget_io_putchar('\r');
            }

            if (CY_RSLT_SUCCESS == rslt)
            {
                rslt = cy_retarget_io_putchar((uint32_t)*ptr);
            }

            if (CY_RSLT_SUCCESS != rslt)
            {
                break;
            }

            cy_retarget_io_stdout_prev_char = *ptr;
            ++ptr;
        }
    }
    return (nChars);
}

int platform_init(void)
{
    SCB->VTOR = (uint32_t)&__Vectors;

    SystemInit();
#if C0_CLK_MAX
    systemclock_config();
#endif

    if (!(uart_init()))
    {
        return -1;
    }

    pins_init();

    printf(CLEARSCREEN);
    printf(RED "System clock configured: %ld.\n", SystemCoreClock);

#ifdef MULTICORE
    printf(RED "Core1 setup and running " INTRFAPP " interf app.\n");
    printf(YELLOW "\t- VTOR: %.8X\n", 0xDEADBEEF);
#endif

#ifdef FPM
    printf(RED "Flash Performance mode configured.\n");
    printf(YELLOW "\t- wait states: %d\n", FLASHC_FLASH_CTL & FLASHC_V2_FLASH_CTL_MAIN_WS_Msk);
    printf(YELLOW "\t- instruction cache ON\n");
    printf(YELLOW "\t- prefetcher ON\n");

    FLASHC->CM0_CA_CTL0 |= FLASHC_CM0_CA_CTL0_ENABLED_Msk;
    FLASHC->CM0_CA_CTL0 |= FLASHC_CM0_CA_CTL0_PREF_EN_Msk;
#else
    FLASHC->CM0_CA_CTL0 &= ~FLASHC_CM0_CA_CTL0_ENABLED_Msk;
    FLASHC->CM0_CA_CTL0 &= ~FLASHC_CM0_CA_CTL0_PREF_EN_Msk;
#endif

#ifdef C0_DMA0
    dma0_init(true);
#endif

#ifdef C0_DMA1
    dma1_init(true);
#endif

    return 0;
}
