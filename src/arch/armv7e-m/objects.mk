arch-objs-y += bootagent.o
ifeq ($(CPU),cortex-m7)
arch-objs-y += startup_ARMCM7.o
endif
ifeq ($(CPU),cortex-m4)
arch-objs-y += startup_ARMCM4.o
endif
arch-objs-y += dwt.o
