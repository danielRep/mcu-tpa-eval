# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Architecture Definition
C0_ARCH		:=	armv6-m
C1_ARCH		:=	armv7e-m

################################################################################
# CPU Definition
C0_CPU		:=	cortex-m0plus
C0_ENDIAN	:=	little-endian
C0_THUMB	:=	thumb

C1_CPU		:=	cortex-m4
C1_ENDIAN	:=	little-endian
C1_THUMB	:=	thumb
C1_ABI		:=	softfp
C1_FPU		:=	fpv4-sp-d16

DEVICE		:=	CYBLE_416045_02_device

################################################################################
# Exporting Flags
plat-flags-c0 = -mcpu=$(C0_CPU) -m$(C0_THUMB) -m$(C0_ENDIAN)

plat-flags-c1 = -mcpu=$(C1_CPU) -m$(C1_THUMB) 		\
			 -m$(C1_ENDIAN) -mfpu=$(C1_FPU) -mfloat-abi=$(C1_ABI)

ifeq ($(PROJ_NAME), core0)
	plat-flags-c0 += -D$(DEVICE)
else ifeq ($(PROJ_NAME), core1)
	plat-flags-c1 += -D$(DEVICE)
endif

