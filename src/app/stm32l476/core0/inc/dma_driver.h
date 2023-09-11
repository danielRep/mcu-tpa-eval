#ifndef __DMA_DRIVER_H__
#define __DMA_DRIVER_H__

#include "stm32l4xx_hal.h"

#define NUMBER_OF_TRANSFERS         (0xffff)     //up to 65535

DMA_HandleTypeDef     Dma1Handle, Dma2Handle;

int dma1_init(void);
int dma1_start(void);
int dma1_polltransfer(void);
void dma1_reinit(void);
void dma1_restart(void);
void dma1_print_copy(uint32_t transfers);

int dma2_init(void);
int dma2_start(void);
int dma2_polltransfer(void);
void dma2_reinit(void);
void dma2_restart(void);
void dma2_print_copy(uint32_t transfers);

#endif  /* __DMA_DRIVER_H__ */
