#include "stm32l4xx_hal.h"
#include "dma_driver.h"
#include "content_eval.h"

/* DMA stream parameters definitions. You can modify these parameters to select*/
/* But note that only DMA2 Streams are capable of Memory to Memory transfers. */
#define DMA_INSTANCE                DMA2_Stream0
#define DMA_CHANNEL                 DMA_CHANNEL_0
#define DMA_INSTANCE_IRQ            DMA2_Stream0_IRQn
#define DMA_INSTANCE_IRQHANDLER     DMA2_Stream0_IRQHandler

#define ALIGNED         __attribute__((aligned(sizeof(uint32_t))))
#define SECTION         __attribute__((section(".dma_buffer")))

ALIGNED const uint32_t src_addr = 0xDEADBEEF;
ALIGNED uint32_t dst_addr;

DMA_HandleTypeDef     DmaHandle;

void dma0_init()
{
    printf(RED"DMA1 memory-to-memory transfer configured and enabled:\n");
    printf(YELLOW"\t- N transfers: %dB\n",NUMBER_OF_TRANSFERS);
    printf(YELLOW"\t- &src_addr: 0x%.8X\n", (unsigned int)&src_addr);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr);
    printf(YELLOW"\t- &dst_addr: 0x%.8X\n", (unsigned int)&dst_addr);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr);
}

void dma0_start(void)
{
    return;
}

void dma_print_copy(void)
{
    printf(GREEN"DMA0 copy verification:\n");
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr);

    /* To make sure that the DMA is working, reset the dst_addr */
    dst_addr = 0xC00010FF;
    printf(YELLOW"\t- reset dst_addr to: 0x%.8lX\n", dst_addr);

}

int dma1_init()
{
    /* 1- Enable DMA2 clock */
    __HAL_RCC_DMA2_CLK_ENABLE();

    /* 2- Select the DMA functional Parameters */
    /* In mem-to-mem operations, the periph fields are an alias to the memory source */
    DmaHandle.Init.Channel = DMA_CHANNEL;                       /* DMA_CHANNEL_0                    */
    DmaHandle.Init.Direction = DMA_MEMORY_TO_MEMORY;            /* M2M transfer mode                */
    DmaHandle.Init.PeriphInc = DMA_PINC_DISABLE;                /* Peripheral increment mode Enable */
    DmaHandle.Init.MemInc = DMA_MINC_DISABLE;                   /* Memory increment mode Enable     */
    DmaHandle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;   /* Peripheral data alignment : Word */
    DmaHandle.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;      /* memory data alignment : Word     */
    DmaHandle.Init.Mode = DMA_NORMAL;                           /* Normal DMA mode                  */
    DmaHandle.Init.Priority = DMA_PRIORITY_HIGH;                /* priority level : high            */
    DmaHandle.Init.FIFOMode = DMA_FIFOMODE_DISABLE;             /* FIFO mode enabled                */
    DmaHandle.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;     /* FIFO threshold: 1/4 full   */
    DmaHandle.Init.MemBurst = DMA_MBURST_SINGLE;                /* Memory burst                     */
    DmaHandle.Init.PeriphBurst = DMA_PBURST_SINGLE;             /* Peripheral burst                 */

    /* 3- Select the DMA instance to be used for the transfer : DMA1_Stream0 */
    DmaHandle.Instance = DMA_INSTANCE;

    /* 4- Initialize the DMA stream */
    if (HAL_DMA_Init(&DmaHandle) != HAL_OK)
    {
        /* Initialization Error */
        return -1;
    }

    /* Enable the DMA STREAM global Interrupt */
    HAL_NVIC_EnableIRQ(DMA_INSTANCE_IRQ);

    printf(RED"DMA2 memory-to-memory transfer configured and enabled:\n");
    printf(YELLOW"\t- N transfers: %dB\n", NUMBER_OF_TRANSFERS);
    printf(YELLOW"\t- &src_addr: 0x%.8X\n", (unsigned int)&src_addr);
    printf(YELLOW"\t- src_addr: 0x%.8lX\n", src_addr);
    printf(YELLOW"\t- &dst_addr: 0x%.8X\n", (unsigned int)&dst_addr);
    printf(YELLOW"\t- dst_addr: 0x%.8lX\n", dst_addr);

    return 0;
}

int dma1_polltransfer(void)
{
    if(HAL_DMA_PollForTransfer(&DmaHandle, HAL_DMA_FULL_TRANSFER, 1000) != HAL_OK)
    {
        return -1;
    }
    return 0;
}

void dma1_reinit(void)
{
    HAL_DMA_Abort_IT(&DmaHandle);
    HAL_DMA_DeInit(&DmaHandle);
    /* Initialize the DMA stream */
    if (HAL_DMA_Init(&DmaHandle) != HAL_OK)
    {
        /* Initialization Error */
        printf(RED "DMA2 reinit error!\n");
    }
    return;
}

void dma1_start(void)
{
    HAL_DMA_Start_IT(&DmaHandle, (uint32_t)&src_addr, (uint32_t)&dst_addr, NUMBER_OF_TRANSFERS);
    return;
}

void dma1_restart(void)
{
    dst_addr += 0x100;
    __HAL_DMA_ENABLE(&DmaHandle);
}
