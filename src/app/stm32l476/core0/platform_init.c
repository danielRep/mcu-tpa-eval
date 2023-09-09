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

#include "stm32l4xx_hal.h"

/* UART handler declaration */
UART_HandleTypeDef UartHandle;

/* Enable HSI oscillator and configure the PLL to reach the max system frequency (216 MHz)
    when using HSEBypass oscillator as PLL clock source. */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
    {
        __disable_irq();
        while(1);
    }

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 1;
    RCC_OscInitStruct.PLL.PLLN = 10;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
    RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        __disable_irq();
        while(1);
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
    {
        __disable_irq();
        while(1);
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    /* Enable GPIO TX/RX clock */
    USARTx_TX_GPIO_CLK_ENABLE();
    USARTx_RX_GPIO_CLK_ENABLE();

    /* Enable USARTx clock */
    USARTx_CLK_ENABLE();

    /*##-2- Configure peripheral GPIO ##########################################*/
    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin = USARTx_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = USARTx_TX_AF;

    HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin = USARTx_RX_PIN;
    GPIO_InitStruct.Alternate = USARTx_RX_AF;

    HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);
}

bool uart_init(void)
{
    UartHandle.Instance = USARTx;

    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_ODD;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    if (HAL_UART_Init(&UartHandle) != HAL_OK)
    {
        return false;
    }

    return true;
}

int _read(int file, char *ptr, int len)
{
    int n_chars = 0;
    uint8_t byte = 0;

    if (ptr != NULL)
    {
        for (n_chars = 0; n_chars < len; ++ptr)
        {
            HAL_UART_Receive(&UartHandle, &byte, 1, 1000);
            *ptr = (char)byte;
            ++n_chars;

            if ((*ptr == '\n') || (*ptr == '\r'))
            {
                break;
            }
        }
    }
    return (n_chars);
}

int _write(int file, const void *ptr, int len)
{
    if (isatty(file))
    {

        for (size_t i = 0; i < len; i++)
        {
            HAL_UART_Transmit(&UartHandle, (uint8_t *)ptr, 1, 1000);

            if (*(uint8_t *)ptr == '\n')
            {
                HAL_UART_Transmit(&UartHandle, (const uint8_t *)"\r", 1, 1000);
            }
        }

        return len;
    }
    return -1;
}

int platform_init(void)
{
#if C0_CLK_MAX
    SystemClock_Config();
    SysTick->CTRL = 0; // Disable Systick
#endif
    if (!(uart_init()))
    {
        return -1;
    }
    printf(CLEAR);
    printf(RED "System clock configured: %ld.\n", SystemCoreClock);

#ifdef FPM
    printf(RED "Flash Performance mode configured.\n");
    printf(YELLOW "\t- Internal I$ ON\n");
    printf(YELLOW "\t- Internal D$ ON\n");
    printf(YELLOW "\t- Prefetcher ON\n");
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#else
    printf(RED "Flash Performance mode disable.\n");
    __HAL_FLASH_PREFETCH_BUFFER_DISABLE();
    __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();
    __HAL_FLASH_DATA_CACHE_DISABLE();
#endif

#ifdef C0_DMA0
    dma0_init();
#endif

#ifdef C0_DMA1
    if (dma1_init() != 0)
    {
        printf(RED "DMA1 init failed.\n");
        return -1;
    }
#endif

    return 0;
}
