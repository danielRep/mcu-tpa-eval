#include "stm32l4xx_hal.h"
#include "dma_driver.h"
#include "content_eval.h"

#define ALIGNED         __attribute__((aligned(sizeof(uint32_t))))
#define SECTION(x)      __attribute__((section(x)))

ALIGNED const uint32_t src_addr1 = 0xDEADBEEF;
ALIGNED uint32_t dst_addr1 = 0xC0FFEE00;
ALIGNED const uint32_t src_addr2 = 0xDEADBEEF;
ALIGNED uint32_t dst_addr2 = 0xC0FFEE00;

DMA_HandleTypeDef     Dma1Handle, Dma2Handle;

int dma1_init()
{
    /* 1- Enable DMA2 clock */
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* 2- Select the DMA functional Parameters */
    /* In mem-to-mem operations, the periph fields are an alias to the memory source */
    Dma1Handle.Init.Request = DMA_REQUEST_0;
    Dma1Handle.Init.Direction = DMA_MEMORY_TO_MEMORY;
    Dma1Handle.Init.PeriphInc = DMA_PINC_ENABLE;
    Dma1Handle.Init.MemInc = DMA_MINC_DISABLE;
    Dma1Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    Dma1Handle.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    Dma1Handle.Init.Mode = DMA_NORMAL;
    Dma1Handle.Init.Priority = DMA_PRIORITY_HIGH;

    /* 3- Select the DMA instance to be used for the transfer : DMA1_Stream0 */
    Dma1Handle.Instance = DMA1_Channel1;

    /* 4- Initialize the DMA stream */
    if (HAL_DMA_Init(&Dma1Handle) != HAL_OK)
    {
        /* Initialization Error */
        return -1;
    }

    /* Enable the DMA STREAM global Interrupt */
    HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

    printf(RED"DMA1 memory-to-memory transfer configured and enabled:\n");
    printf(YELLOW"\t- N transfers: %dB\n", NUMBER_OF_TRANSFERS);
    printf(YELLOW"\t- &src_addr: 0x%.8X\n", (unsigned int)&src_addr1);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr1);
    printf(YELLOW"\t- &dst_addr: 0x%.8X\n", (unsigned int)&dst_addr1);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr1);

    return 0;
}

int dma1_start(void)
{
    if(HAL_DMA_Start_IT(&Dma1Handle, (uint32_t)&src_addr1, (uint32_t)&dst_addr1, NUMBER_OF_TRANSFERS) !=0)
    {
        printf(RED"DMA1 start error!\n");
        return -1;
    }

    return 0;
}

int dma1_polltransfer(void)
{
    if(HAL_DMA_PollForTransfer(&Dma1Handle, HAL_DMA_FULL_TRANSFER, 1000) != HAL_OK)
    {
        return -1;
    }
    return 0;
}

void dma1_reinit(void)
{
    HAL_DMA_Abort_IT(&Dma1Handle);
    HAL_DMA_DeInit(&Dma1Handle);
    /* Initialize the DMA stream */
    if (HAL_DMA_Init(&Dma1Handle) != HAL_OK)
    {
        /* Initialization Error */
        printf(RED "DMA2 reinit error!\n");
    }
    return;
}

void dma1_restart(void)
{
    __HAL_DMA_ENABLE(&Dma1Handle);
}

void dma1_print_copy(uint32_t transfers)
{
    printf(GREEN"DMA1 copy verification:\n");
    printf(YELLOW"\t- transfers: %ld\n", transfers);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr1);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr1);

    /* To make sure that the DMA is working, reset the dst_addr */
    dst_addr1 = 0xC00010FF;
    printf(YELLOW"\t- redefined dst_addr to: 0x%.8lX\n", dst_addr1);

}

int dma2_init()
{
    /* 1- Enable DMA2 clock */
    __HAL_RCC_DMA2_CLK_ENABLE();

    /* 2- Select the DMA functional Parameters */
    /* In mem-to-mem operations, the periph fields are an alias to the memory source */
    Dma2Handle.Init.Request = DMA_REQUEST_0;
    Dma2Handle.Init.Direction = DMA_MEMORY_TO_MEMORY;
    Dma2Handle.Init.PeriphInc = DMA_PINC_ENABLE;
    Dma2Handle.Init.MemInc = DMA_MINC_DISABLE;
    Dma2Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    Dma2Handle.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    Dma2Handle.Init.Mode = DMA_NORMAL;
    Dma2Handle.Init.Priority = DMA_PRIORITY_HIGH;

    /* 3- Select the DMA instance to be used for the transfer : DMA1_Stream0 */
    Dma2Handle.Instance = DMA2_Channel1;

    /* 4- Initialize the DMA stream */
    if (HAL_DMA_Init(&Dma2Handle) != HAL_OK)
    {
        /* Initialization Error */
        return -1;
    }

    /* Enable the DMA STREAM global Interrupt */
    HAL_NVIC_EnableIRQ(DMA2_Channel1_IRQn);

    printf(RED"DMA2 memory-to-memory transfer configured and enabled:\n");
    printf(YELLOW"\t- N transfers: %dB\n", NUMBER_OF_TRANSFERS);
    printf(YELLOW"\t- &src_addr: 0x%.8X\n", (unsigned int)&src_addr2);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr2);
    printf(YELLOW"\t- &dst_addr: 0x%.8X\n", (unsigned int)&dst_addr2);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr2);

    return 0;
}

int dma2_start(void)
{
    if(HAL_DMA_Start_IT(&Dma2Handle, (uint32_t)&src_addr2, (uint32_t)&dst_addr2, NUMBER_OF_TRANSFERS) !=0)
    {
        printf(RED"DMA2 start error!\n");
        return -1;
    }
    return 0;
}

int dma2_polltransfer(void)
{
    if(HAL_DMA_PollForTransfer(&Dma2Handle, HAL_DMA_FULL_TRANSFER, 1000) != HAL_OK)
    {
        return -1;
    }
    return 0;
}

void dma2_reinit(void)
{
    HAL_DMA_Abort_IT(&Dma2Handle);
    HAL_DMA_DeInit(&Dma2Handle);
    /* Initialize the DMA stream */
    if (HAL_DMA_Init(&Dma2Handle) != HAL_OK)
    {
        /* Initialization Error */
        printf(RED "DMA2 reinit error!\n");
    }
    return;
}

void dma2_restart(void)
{
    __HAL_DMA_ENABLE(&Dma2Handle);
}

void dma2_print_copy(uint32_t transfers)
{
    printf(GREEN"DMA2 copy verification:\n");
    printf(YELLOW"\t- transfers: %ld\n", transfers);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr2);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr2);

    /* To make sure that the DMA is working, reset the dst_addr */
    dst_addr2 = 0xC00010FF;
    printf(YELLOW"\t- redefined dst_addr to: 0x%.8lX\n", dst_addr2);

}
q