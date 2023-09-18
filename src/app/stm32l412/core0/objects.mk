core0-objs-y += main_eval.o
ifeq ($(or $(C0_DMA1),$(C0_DMA0)), y)
core0-objs-y += dma_driver.o
endif
core0-objs-y += system_stm32l4xx.o
core0-objs-y += platform_init.o
