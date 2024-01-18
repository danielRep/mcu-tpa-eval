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
#include "uart_pl011.h"
#include "cache_drv.h"
#include "sse200_regs.h"

static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_NS =
{
    .base = MUSCA_UART0_S_BASE,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1
};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_NS =
{
    .state = UART_PL011_UNINITIALIZED,
    .uart_clk = 0,
    .baudrate = 0
};
struct uart_pl011_dev_t UART0_PL011_DEV_NS =
{
    &(UART0_PL011_DEV_CFG_NS),
    &(UART0_PL011_DEV_DATA_NS)
};

bool uart_init(void)
{
    //115200, 8 bits, no parity, 1 stop bit
    uart_pl011_init(&UART0_PL011_DEV_NS, CPU_MHZ);
    uart_pl011_enable(&UART0_PL011_DEV_NS);

    if (uart_pl011_is_writable(&UART0_PL011_DEV_NS))
        return true;

    return false;
}

int _read(int file, char *ptr, int len)
{
    int n_chars = 0;
    uint8_t byte = 0;

    if(ptr != NULL)
    {
        for(n_chars = 0; n_chars < len; ++ptr)
        {
            while (!uart_pl011_is_readable(&UART0_PL011_DEV_NS)){};
            uart_pl011_read(&UART0_PL011_DEV_NS, &byte);
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

int _write(int file, const void *ptr, int len)
{
    if (isatty(file)) {

        const uint8_t * buff = (uint8_t *)ptr;

        for (size_t i = 0; i < len; i++) {

            while(!uart_pl011_is_writable(&UART0_PL011_DEV_NS)) {};

            (void)uart_pl011_write(&UART0_PL011_DEV_NS, buff[i]);

            if (buff[i] == '\n') {
                while(!uart_pl011_is_writable(&UART0_PL011_DEV_NS)) {};
                (void)uart_pl011_write(&UART0_PL011_DEV_NS, (uint8_t)'\r');
            }
        }

        return len;

    }
    return -1;
}

void iomux_cfg_uart0(void)
{
    //UART0_RxD
    SCC->IOMUX_ALTF1_OENSEL |= (1<<0);

    SCC->IOMUX_MAIN_INSEL  &= ~(1<<0);
    SCC->IOMUX_MAIN_OUTSEL &= ~(1<<0);
    SCC->IOMUX_MAIN_OENSEL &= ~(1<<0);

    SCC->IOMUX_ALTF2_INSEL  &= ~(1<<0);
    SCC->IOMUX_ALTF2_OUTSEL &= ~(1<<0);
    SCC->IOMUX_ALTF2_OENSEL &= ~(1<<0);

    SCC->IOMUX_ALTF1_INSEL  |= (1<<0);
    SCC->IOMUX_ALTF1_OUTSEL |= (1<<0);

    //UART0_TxD
    SCC->IOMUX_ALTF1_OENSEL |= (1<<1);

    SCC->IOMUX_MAIN_INSEL &= ~(1<<1);
    SCC->IOMUX_MAIN_OUTSEL &= ~(1<<1);
    SCC->IOMUX_MAIN_OENSEL &= ~(1<<1);

    SCC->IOMUX_ALTF2_INSEL  &= ~(1<<1);
    SCC->IOMUX_ALTF2_OUTSEL &= ~(1<<1);
    SCC->IOMUX_ALTF2_OENSEL &= ~(1<<1);

    SCC->IOMUX_ALTF1_INSEL  |= (1<<1);
    SCC->IOMUX_ALTF1_OUTSEL |= (1<<1);
}

int platform_init(void)
{
    iomux_cfg_uart0();

    if(!(uart_init()))
        return -1;

    printf(CLEAR);
#ifdef C1_IC
    static const struct arm_cache_dev_cfg_t SSE_200_CACHE_CFG_S = {
    .base = MUSCA_CPU_ELEMENT_S_BASE};

    struct arm_cache_dev_t SSE_200_CACHE_DEV_S = {&(SSE_200_CACHE_CFG_S)};

    if(!arm_cache_is_enabled(&SSE_200_CACHE_DEV_S))
    {
        arm_cache_full_invalidate(&SSE_200_CACHE_DEV_S);
        printf(RED "ICache on core1 enabled.\n");
        arm_cache_enable(&SSE_200_CACHE_DEV_S);
#ifdef C1_IC_STATS
        printf(YELLOW "\t- stats ON\n");
        arm_cache_statistic_enable(&SSE_200_CACHE_DEV_S);
#endif
    }
#endif

    return 0;
}
