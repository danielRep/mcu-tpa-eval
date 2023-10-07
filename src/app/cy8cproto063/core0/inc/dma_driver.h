#ifndef __DMA_DRIVER_H__
#define __DMA_DRIVER_H__

#include "content_eval.h"

void dma0_init(bool print);
void dma0_start(void);
void dma0_ch_disable(void);
void dma0_print_copy(void);
void dma0_reinit(void);

void dma1_init(bool print);
void dma1_start(void);
void dma1_ch_disable(void);
void dma1_print_copy(void);
void dma1_reinit(void);

#endif  /* __DMA_DRIVER_H__ */
