#include "dma_driver.h"
#include "mem_defs.h"

#include "cy_dma.h"
#include "cy_sysint.h"
#include "cy_trigmux.h"

#define BUFF_LENGTH (200 * 100) // xCount * yCount

#define Dma0_HW DW0
#define Dma0_CHANNEL 0U
#define Dma0_IRQ cpuss_interrupts_dw0_0_IRQn

#define Dma1_HW DW1
#define Dma1_CHANNEL 0U
#define Dma1_IRQ cpuss_interrupts_dw1_0_IRQn

volatile uint32_t total_transfers1 = 0;
volatile uint32_t total_transfers2 = 0;

void handle_error(void);

cy_stc_dma_descriptor_t Dma0_Descriptor_0 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL,
};
cy_stc_dma_descriptor_t Dma1_Descriptor_0 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL,
};

const cy_stc_dma_descriptor_config_t Dma0_Descriptor_0_config =
{
    .retrigger = CY_DMA_RETRIG_IM,
    .interruptType = CY_DMA_DESCR,
    .triggerOutType = CY_DMA_DESCR,
    .channelState = CY_DMA_CHANNEL_DISABLED,
    .triggerInType = CY_DMA_DESCR,
    .dataSize = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType = CY_DMA_2D_TRANSFER,
    .srcAddress = NULL,
    .dstAddress = NULL,
    .srcXincrement = 0,
    .dstXincrement = 1,
    .xCount = 200,
    .srcYincrement = 0,
    .dstYincrement = 200,
    .yCount = 100,
    .nextDescriptor = &Dma0_Descriptor_0,
};
const cy_stc_dma_descriptor_config_t Dma1_Descriptor_0_config =
{
    .retrigger = CY_DMA_RETRIG_IM,
    .interruptType = CY_DMA_DESCR,
    .triggerOutType = CY_DMA_DESCR,
    .channelState = CY_DMA_CHANNEL_DISABLED,
    .triggerInType = CY_DMA_DESCR,
    .dataSize = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType = CY_DMA_2D_TRANSFER,
    .srcAddress = NULL,
    .dstAddress = NULL,
    .srcXincrement = 0,
    .dstXincrement = 1,
    .xCount = 200,
    .srcYincrement = 0,
    .dstYincrement = 200,
    .yCount = 100,
    .nextDescriptor = &Dma1_Descriptor_0,
};

const cy_stc_dma_channel_config_t Dma0_channelConfig =
{
    .descriptor = &Dma0_Descriptor_0,
    .preemptable = false,
    .priority = 3,
    .enable = false,
    .bufferable = false,
};
const cy_stc_dma_channel_config_t Dma1_channelConfig =
{
    .descriptor = &Dma1_Descriptor_0,
    .preemptable = false,
    .priority = 3,
    .enable = false,
    .bufferable = false,
};

#define ALIGNED __attribute__((aligned(sizeof(uint32_t))))

ALIGNED const uint32_t src_buff = 0xDEADBEEF;
ALIGNED uint32_t dst_buff1[BUFF_LENGTH] = {[0 ... BUFF_LENGTH - 1] = 0xC0FFEE00};
ALIGNED uint32_t dst_buff2[BUFF_LENGTH] = {[0 ... BUFF_LENGTH - 1] = 0xC0FFEE00};

void Interrupt8_Handler(void)
{
    // Disable DMA0 interrupt
    Cy_DMA_Channel_ClearInterrupt(Dma0_HW, Dma0_CHANNEL);
    total_transfers1++;
    dma0_start();
}

void Interrupt9_Handler(void)
{
    // Disable DMA0 interrupt
    Cy_DMA_Channel_ClearInterrupt(Dma1_HW, Dma1_CHANNEL);
    total_transfers2++;
    dma1_start();
}

void dma0_init(bool print)
{
    cy_en_dma_status_t dma_init_status;

    /* Initialize descriptor 1 */
    dma_init_status = Cy_DMA_Descriptor_Init(&Dma0_Descriptor_0, &Dma0_Descriptor_0_config);
    if (dma_init_status != CY_DMA_SUCCESS)
    {
        handle_error();
    }

    dma_init_status = Cy_DMA_Channel_Init(Dma0_HW, Dma0_CHANNEL, &Dma0_channelConfig);
    if (dma_init_status != CY_DMA_SUCCESS)
    {
        handle_error();
    }

    /* Set source and destination address for descriptor 1 */
    Cy_DMA_Descriptor_SetSrcAddress(&Dma0_Descriptor_0, &src_buff);
    Cy_DMA_Descriptor_SetDstAddress(&Dma0_Descriptor_0, &dst_buff1);

    Cy_DMA_Channel_SetDescriptor(Dma0_HW, Dma0_CHANNEL, &Dma0_Descriptor_0);

    /* Initialize and enable interrupt from RxDma */
    NVIC_EnableIRQ(NvicMux8_IRQn);
    Cy_SysInt_SetInterruptSource(NvicMux8_IRQn, Dma0_IRQ);
    /* Enable DMA interrupt source. */
    Cy_DMA_Channel_SetInterruptMask(Dma0_HW, Dma0_CHANNEL, CY_DMA_INTR_MASK);

    if (print)
    {
        printf(RED "DMA0 2D transfer configured and enabled:\n");
        printf(YELLOW "\t- src buffers size: %dB\n", BUFF_LENGTH);
        printf(YELLOW "\t- active channel: %d\n", Dma0_CHANNEL);
        printf(YELLOW "\t- src_buffers: 0x%.8X\n", (unsigned int)&src_buff);
        printf(YELLOW "\t- dst_buffer: 0x%.8X\n", (unsigned int)&dst_buff1[0]);
    }
}

void dma0_ch_disable(void)
{
    Cy_DMA_Channel_Disable(Dma0_HW, Dma0_CHANNEL);
    return;
}

void dma0_start(void)
{
    /* Enable channel and DMA block to start descriptor execution process */
    Cy_DMA_Channel_Enable(Dma0_HW, Dma0_CHANNEL);
    Cy_DMA_Enable(Dma0_HW);
    Cy_TrigMux_SwTrigger(0x0, CY_TRIGGER_TWO_CYCLES);
    return;
}

__attribute__((optimize(0))) void dma0_print_copy()
{
    printf(GREEN "DMA0 copy verification:\n");
    printf(YELLOW "\t- transfers: %ld\n", total_transfers1);
    printf(YELLOW "\t- src_addr: 0x%.8lX\n", src_buff);
    printf(YELLOW "\t- dst_addr[0]: 0x%.8lX\n", dst_buff1[0]);
    printf(YELLOW "\t- dst_addr[SIZE-1]: 0x%.8lX\n", dst_buff1[BUFF_LENGTH - 2]);

    /* To make sure that the DMA is working, reset the dst_addr */
    dst_buff1[0] = 0xC0FFEE00;
    dst_buff1[BUFF_LENGTH - 2] = 0xC0FFEE00;
    printf(YELLOW "...\n");
    printf(YELLOW "\t- redefined dst_addr to: 0x%.8lX\n", dst_buff1[0]);
    printf(YELLOW "\t- redefined dst_addr to: 0x%.8lX\n", dst_buff1[BUFF_LENGTH - 2]);
}

void dma0_reinit(void)
{
    Cy_DMA_Channel_DeInit(Dma0_HW, Dma0_CHANNEL);
    dma0_init(false);
}

void dma1_init(bool print)
{
    cy_en_dma_status_t dma_init_status;

    /* Initialize descriptor 1 */
    dma_init_status = Cy_DMA_Descriptor_Init(&Dma1_Descriptor_0, &Dma1_Descriptor_0_config);
    if (dma_init_status != CY_DMA_SUCCESS)
    {
        handle_error();
    }

    dma_init_status = Cy_DMA_Channel_Init(Dma1_HW, Dma0_CHANNEL, &Dma1_channelConfig);
    if (dma_init_status != CY_DMA_SUCCESS)
    {
        handle_error();
    }

    /* Set source and destination address for descriptor 1 */
    Cy_DMA_Descriptor_SetSrcAddress(&Dma1_Descriptor_0, &src_buff);
    Cy_DMA_Descriptor_SetDstAddress(&Dma1_Descriptor_0, &dst_buff2);

    Cy_DMA_Channel_SetDescriptor(Dma1_HW, Dma1_CHANNEL, &Dma1_Descriptor_0);

    /* Initialize and enable interrupt from RxDma */
    NVIC_EnableIRQ(NvicMux9_IRQn);
    Cy_SysInt_SetInterruptSource(NvicMux9_IRQn, Dma0_IRQ);

    /* Enable DMA interrupt source. */
    Cy_DMA_Channel_SetInterruptMask(Dma1_HW, Dma1_CHANNEL, CY_DMA_INTR_MASK);

    if (print)
    {
        printf(RED "DMA1 2D transfer configured and enabled:\n");
        printf(YELLOW "\t- src buffers size: %dB\n", BUFF_LENGTH);
        printf(YELLOW "\t- active channel: %d\n", Dma1_CHANNEL);
        printf(YELLOW "\t- src_buffers: 0x%.8X\n", (unsigned int)&src_buff);
        printf(YELLOW "\t- dst_buffer: 0x%.8X\n", (unsigned int)&dst_buff2[0]);
    }
}

void dma1_ch_disable(void)
{
    Cy_DMA_Channel_Disable(Dma1_HW, Dma1_CHANNEL);
    return;
}

void dma1_start(void)
{
    /* Enable channel and DMA block to start descriptor execution process */
    Cy_DMA_Channel_Enable(Dma1_HW, Dma1_CHANNEL);
    Cy_DMA_Enable(Dma1_HW);

    Cy_TrigMux_SwTrigger(0x100, CY_TRIGGER_TWO_CYCLES);
    return;
}

__attribute__((optimize(0))) void dma1_print_copy()
{
    printf(GREEN "DMA1 copy verification:\n");
    printf(YELLOW "\t- transfers: %ld\n", total_transfers2);
    printf(YELLOW "\t- src_addr: 0x%.8lX\n", src_buff);
    printf(YELLOW "\t- dst_addr[0]: 0x%.8lX\n", dst_buff2[0]);
    printf(YELLOW "\t- dst_addr[SIZE-1]: 0x%.8lX\n", dst_buff2[BUFF_LENGTH - 2]);

    __DSB();
    __ISB();

    /* To make sure that the DMA is working, reset the dst_addr */
    dst_buff2[0] = 0xC0FFEE00;
    dst_buff2[BUFF_LENGTH - 2] = 0xC0FFEE00;
    printf(YELLOW "...\n");
    printf(YELLOW "\t- redefined dst_addr to: 0x%.8lX\n", dst_buff2[0]);
    printf(YELLOW "\t- redefined dst_addr to: 0x%.8lX\n", dst_buff2[BUFF_LENGTH - 2]);
}

void dma1_reinit(void)
{
    Cy_DMA_Channel_DeInit(Dma1_HW, Dma1_CHANNEL);
    dma1_init(false);
}

void handle_error()
{
    __disable_irq();
    __asm("bkpt    1");
}