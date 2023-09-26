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

usart_config_t usart_core1_cfg =
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

    /* attach 12 MHz clock to FLEXCOMM2 (debug console) */
    CLOCK_AttachClk(UART2_CLK_ATTACH);
    RESET_ClearPeripheralReset(UART2_RST);
    status = USART_Init(USART2, &usart_core1_cfg, UART2_CLK_FREQ);

    if(status!=kStatus_Success)
        return false;

    return true;
}

void pins_init(void)
{
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);
    CLOCK_EnableClock(kCLOCK_Iocon);


    IOCON->PIO[0][27] = ((IOCON->PIO[0][27] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT027 (pin 27) is configured as FC2_TXD_SCL_MISO_WS. */
                         | IOCON_PIO_FUNC(PIO0_27_FUNC_ALT1)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_27_DIGIMODE_DIGITAL));

    IOCON->PIO[1][24] = ((IOCON->PIO[1][24] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT124 (pin 3) is configured as FC2_RXD_SDA_MOSI_DATA. */
                         | IOCON_PIO_FUNC(PIO1_24_FUNC_ALT1)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO1_24_DIGIMODE_DIGITAL));
}

int _read(int file, char *ptr, int len)
{
    int n_chars = 0;
    uint8_t byte;

    if(ptr != NULL)
    {
        for(n_chars = 0; n_chars < len; ++ptr)
        {
            while ((USART2->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK) == 0U);
            USART_ReadBlocking(USART2, &byte, 1);
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
            while (0U == (USART2->STAT & USART_STAT_TXIDLE_MASK));
            USART_WriteBlocking(USART2, &ptr[i], 1);
        }

        return len;

    }
    return -1;
}

void mailbox_init(void)
{
    /* Enable NVIC IRQ */
    EnableIRQ(MAILBOX_IRQn);
}

int platform_init(void)
{
    if(!(uart_init()))
        return -1;

    pins_init();
    mailbox_init();

    printf(CLEARSCREEN);

    return 0;
}
