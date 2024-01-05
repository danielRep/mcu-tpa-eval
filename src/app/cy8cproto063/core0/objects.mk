CPU		:=	cortex-m0plus

core0-objs-y += main_eval.o
core0-objs-y += system_psoc6_cm0plus.o
core0-objs-y += platform_init.o
ifneq (,$(filter y,$(C0_DMA0) $(C0_DMA1)))
core0-objs-y += dma_driver.o
endif