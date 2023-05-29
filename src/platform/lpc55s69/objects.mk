plat-objs-y += fsl_power.o
plat-objs-y += fsl_common_arm.o
plat-objs-y += fsl_clock.o
plat-objs-y += fsl_reset.o
plat-objs-y += fsl_flexcomm.o
plat-objs-y += fsl_usart.o
ifneq (,$(filter y,$(C0_DMA0) $(C0_DMA1)))
plat-objs-y += fsl_dma.o
endif
