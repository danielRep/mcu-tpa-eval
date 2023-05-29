core0-objs-y += main.o
core0-objs-y += system_LPC55S69_cm33_core0.o
core0-objs-y += platform_init.o
ifneq (,$(filter y,$(C0_DMA0) $(C0_DMA1)))
core0-objs-y += dma_driver.o
endif