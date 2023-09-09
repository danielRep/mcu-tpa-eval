#ifndef __DMA_DRIVER_H__
#define __DMA_DRIVER_H__

#include "stm32l4xx_hal.h"

#define NUMBER_OF_TRANSFERS         (0xffff)     //up to 65535

void dma0_init(void);
void dma0_start(void);

int dma1_init(void);
void dma1_start(void);
int dma1_polltransfer(void);
void dma1_reinit(void);
void dma1_restart(void);

void dma_print_copy(void);
void assembly_loop(void);
void dma_get_handle(DMA_HandleTypeDef **hdma);
void dma_pooling(void);
#endif  /* __DMA_DRIVER_H__ */
