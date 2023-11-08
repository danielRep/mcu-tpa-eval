#include "fsl_dma.h"
#include "dma_driver.h"
#include "content_eval.h"

#define BUFF_LENGTH     ((4096)/4)
#define DMA0_ACTIVE_CH   0
#define DMA1_ACTIVE_CH   0
#define ALIGNED         __attribute__((aligned(sizeof(uint32_t))))

ALIGNED const uint32_t src_buff1[BUFF_LENGTH/2] = {[0 ... BUFF_LENGTH/2-1] = 1};
ALIGNED const uint32_t src_buff2[BUFF_LENGTH/2] = {[0 ... BUFF_LENGTH/2-1] = 2};
ALIGNED uint32_t dst_buff1[BUFF_LENGTH] = {[0 ... BUFF_LENGTH-1] = 0xDEADBEEF};

ALIGNED const uint32_t src_buff3[BUFF_LENGTH/2] = {[0 ... BUFF_LENGTH/2-1] = 1};
ALIGNED const uint32_t src_buff4[BUFF_LENGTH/2] = {[0 ... BUFF_LENGTH/2-1] = 2};
ALIGNED uint32_t dst_buff2[BUFF_LENGTH] = {[0 ... BUFF_LENGTH-1] = 0xDEADBEEF};

__attribute__((aligned(sizeof(dma_descriptor_t)))) dma_descriptor_t dma0_tbl[2];
__attribute__((aligned(sizeof(dma_descriptor_t)))) dma_descriptor_t dma1_tbl[2];
static dma_handle_t dma0_hndl, dma1_hndl;

void dma0_init()
{
    DMA_Init(DMA0);
    DMA_CreateHandle(&dma0_hndl, DMA0, DMA0_ACTIVE_CH);
    DMA_EnableChannel(DMA0, DMA0_ACTIVE_CH);
    DMA_SetupDescriptor(&(dma0_tbl[0]),
                        DMA_CHANNEL_XFER(true, false, false, false, 4U, kDMA_AddressInterleave1xWidth,
                                         kDMA_AddressInterleave1xWidth, 4*(BUFF_LENGTH/2)),
                        src_buff1, &dst_buff1[0], &(dma0_tbl[1]));
    DMA_SetupDescriptor(&(dma0_tbl[1]),
                        DMA_CHANNEL_XFER(true, false, false, false, 4U, kDMA_AddressInterleave1xWidth,
                                         kDMA_AddressInterleave1xWidth, 4*(BUFF_LENGTH/2)),
                        src_buff2, &dst_buff1[BUFF_LENGTH/2], &(dma0_tbl[0]));
    DMA_SubmitChannelDescriptor(&dma0_hndl, &(dma0_tbl[0]));

    printf(RED"DMA0 linked transfer configured and enabled:\n");
    printf(YELLOW"\t- src buffers size: %dB\n",BUFF_LENGTH*4);
    printf(YELLOW"\t- active channel: %d\n",DMA0_ACTIVE_CH);
    printf(YELLOW"\t- src_buffers: 0x%.8X & 0x%.8x\n", (unsigned int)&src_buff1[0], (unsigned int)&src_buff2[0]);
    printf(YELLOW"\t- dst_buffer: 0x%.8X\n", (unsigned int)&dst_buff1[0]);
}


void dma0_ch_disable(void)
{
    DMA_DisableChannel(DMA0, DMA0_ACTIVE_CH);
    return;
}

void dma0_start(void)
{
    DMA_StartTransfer(&dma0_hndl);
    return;
}

void dma0_print_dst(void)
{
    printf(GREEN"DMA0 copy verification:\n");
    printf(YELLOW"\t- src_buff[0]: 0x%.8lX\n", src_buff1[0]);
    printf(YELLOW"\t- dst_buff[0]: 0x%.8lX\n", dst_buff1[0]);

    /* To make sure that the DMA is working, reset the dst_buff */
    dst_buff1[0] = 0xDEADBEEF;
    printf(YELLOW"\t- redefined dst_buff to: 0x%.8lX\n", dst_buff1[0]);
}

void dma1_init()
{
    DMA_Init(DMA1);
    DMA_CreateHandle(&dma1_hndl, DMA1, DMA1_ACTIVE_CH);
    DMA_EnableChannel(DMA1, DMA1_ACTIVE_CH);
    DMA_SetupDescriptor(&(dma1_tbl[0]),
                        DMA_CHANNEL_XFER(true, false, false, false, 4U, kDMA_AddressInterleave1xWidth,
                                         kDMA_AddressInterleave1xWidth, 4*(BUFF_LENGTH/2)),
                        src_buff3, &dst_buff2[0], &(dma1_tbl[1]));
    DMA_SetupDescriptor(&(dma1_tbl[1]),
                        DMA_CHANNEL_XFER(true, false, false, false, 4U, kDMA_AddressInterleave1xWidth,
                                         kDMA_AddressInterleave1xWidth, 4*(BUFF_LENGTH/2)),
                        src_buff4, &dst_buff2[BUFF_LENGTH/2], &(dma1_tbl[0]));
    DMA_SubmitChannelDescriptor(&dma1_hndl, &(dma1_tbl[0]));

    printf(RED"DMA1 linked transfer configured and enabled:\n");
    printf(YELLOW"\t- src buffers size: %dB\n",BUFF_LENGTH*4);
    printf(YELLOW"\t- active channel: %d\n",DMA0_ACTIVE_CH);
    printf(YELLOW"\t- src_buffers: 0x%.8X & 0x%.8x\n", (unsigned int)&src_buff3[0], (unsigned int)&src_buff4[0]);
    printf(YELLOW"\t- dst_buffer: 0x%.8X\n", (unsigned int)&dst_buff2[0]);
}


void dma1_ch_disable(void)
{
    DMA_DisableChannel(DMA1, DMA1_ACTIVE_CH);
    return;
}

void dma1_start(void)
{
    DMA_StartTransfer(&dma1_hndl);
    return;
}

void dma1_print_dst(void)
{
    printf(GREEN"DMA1 copy verification:\n");
    printf(YELLOW"\t- src_buff[0]: 0x%.8lX\n", src_buff3[0]);
    printf(YELLOW"\t- dst_buff[0]: 0x%.8lX\n", dst_buff2[0]);

    /* To make sure that the DMA is working, reset the dst_buff */
    dst_buff2[0] = 0xDEADBEEF;
    printf(YELLOW"\t- redefined dst_buff to: 0x%.8lX\n", dst_buff2[0]);
}