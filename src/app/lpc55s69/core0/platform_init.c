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
#include "fsl_usart.h"
#include "fsl_clock.h"
#include "fsl_iocon.h"
#include "pin_mux.h"
#include "dma_driver.h"

usart_config_t usart_core0_cfg =
{
    .baudRate_Bps = 115200,
    .parityMode = kUSART_ParityDisabled,
    .stopBitCount = kUSART_OneStopBit,
    .bitCountPerChar = kUSART_8BitsPerChar,
    .loopback = false,
    .enableRx = true,
    .enableTx = true,
    .enableContinuousSCLK = false,
    .enableMode32k = false,
    .enableHardwareFlowControl = false,
    .txWatermark = kUSART_TxFifo0,
    .rxWatermark = kUSART_RxFifo1,
    .syncMode = kUSART_SyncModeDisabled,
    .clockPolarity = kUSART_RxSampleOnFallingEdge,
};

bool uart_init(void)
{
    status_t status;

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(UART0_CLK_ATTACH);
    RESET_ClearPeripheralReset(UART0_RST);
    status = USART_Init(USART0, &usart_core0_cfg, UART0_CLK_FREQ);

    if(status!=kStatus_Success)
        return false;

    return true;
}

void pins_init(void)
{
    CLOCK_EnableClock(kCLOCK_Iocon);

    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI_DATA */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: 92) is configured as FC0_RXD_SDA_MOSI_DATA */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO_WS */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: 94) is configured as FC0_TXD_SCL_MISO_WS */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);
}

void mailbox_init(void)
{
    /* Enable clock for inter CPU communication */
    CLOCK_EnableClock(kCLOCK_Mailbox);

    /* Reset mailbox peripheral */
    RESET_PeripheralReset(kMAILBOX_RST_SHIFT_RSTn);

    /* Enable NVIC IRQ */
    EnableIRQ(MAILBOX_IRQn);
}

int _read(int file, char *ptr, int len)
{
    int n_chars = 0;
    uint8_t byte;

    if(ptr != NULL)
    {
        for(n_chars = 0; n_chars < len; ++ptr)
        {
            while ((USART0->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK) == 0U);
            USART_ReadBlocking(USART0, &byte, 1);
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
            while (0U == (USART0->STAT & USART_STAT_TXIDLE_MASK));
            USART_WriteBlocking(USART0, &ptr[i], 1);
        }

        return len;

    }
    return -1;
}

int platform_init(void)
{
    if(!(uart_init()))
    {
        return -1;
    }

    pins_init();
    mailbox_init();

    printf(CLEAR);

#ifdef MULTICORE
    printf(RED "Core1 setup and running.\n");
    printf(YELLOW "\t- VTOR: %.8X\n", (unsigned int)((SYSCON->CPBOOT)&SYSCON_CPBOOT_CPBOOT_MASK));
#endif

#ifdef FPM
    printf(RED "Flash Performance mode configured.\n");
    printf(YELLOW "\t- accelerator ON\n");
    printf(YELLOW "\t- prefetcher ON\n");
    SYSCON->FMCCR &= ~(SYSCON_FMCCR_FETCHCFG_MASK | SYSCON_FMCCR_DATACFG_MASK | SYSCON_FMCCR_ACCEL_MASK | SYSCON_FMCCR_PREFEN_MASK);
    SYSCON->FMCCR |= SYSCON_FMCCR_FETCHCFG(2);
    SYSCON->FMCCR |= SYSCON_FMCCR_DATACFG(2);
    SYSCON->FMCCR |= SYSCON_FMCCR_ACCEL(1);
    SYSCON->FMCCR |= SYSCON_FMCCR_PREFEN(1);
#else
    SYSCON->FMCCR &= ~(SYSCON_FMCCR_FETCHCFG_MASK | SYSCON_FMCCR_DATACFG_MASK | SYSCON_FMCCR_ACCEL_MASK | SYSCON_FMCCR_PREFEN_MASK);
#endif

#ifdef BUS_PRIO
    printf(RED "Bus priority enabled and configured:\n");
#ifdef C0_PRIO
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_CPU0_CBUS(C0_PRIO);
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_CPU0_SBUS(C0_PRIO);
    printf(YELLOW "\t- cpu0_prio: %ld\n", ((SYSCON->AHBMATPRIO)&SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK)>> SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT);
#endif
#ifdef C1_PRIO
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_CPU1_CBUS(C1_PRIO);
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_CPU1_SBUS(C1_PRIO);
    printf(YELLOW "\t- cpu1_prio: %ld\n", ((SYSCON->AHBMATPRIO)&SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_MASK) >> SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SHIFT);
#endif
#ifdef DMA0_PRIO
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_SDMA0(DMA0_PRIO);
    printf(YELLOW "\t- dma0_prio: %ld\n", ((SYSCON->AHBMATPRIO)&SYSCON_AHBMATPRIO_PRI_SDMA0_MASK) >> SYSCON_AHBMATPRIO_PRI_SDMA0_SHIFT);
#endif
#ifdef DMA1_PRIO
    SYSCON->AHBMATPRIO |= SYSCON_AHBMATPRIO_PRI_SDMA1(DMA1_PRIO);
    printf(YELLOW "\t- dma1_prio: %ld\n", ((SYSCON->AHBMATPRIO)&SYSCON_AHBMATPRIO_PRI_SDMA1_MASK) >> SYSCON_AHBMATPRIO_PRI_SDMA1_SHIFT);
#endif
    printf(YELLOW "\t- SYSCON->AHBMATPRIO=0x%.8lX\n",((SYSCON->AHBMATPRIO)));
#endif

#ifdef C0_DMA0
    dma0_init();
#endif

#ifdef C0_DMA1
    dma1_init();
#endif

    return 0;
}
