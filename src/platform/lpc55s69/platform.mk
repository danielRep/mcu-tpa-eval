# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Architecture Definition
ARCH	:=	armv8-m.main

################################################################################
# CPU Definition
CPU		:=	cortex-m33+nodsp
ENDIAN	:=	little-endian
THUMB	:=	thumb
ABI		:=	soft
FPU		:=	fpv5-sp-d16

################################################################################
# Exporting Flags
plat-flags = -march=$(ARCH) -mcpu=$(CPU) -m$(THUMB) 		\
			 -m$(ENDIAN) -mfloat-abi=$(ABI) -mfpu=$(FPU)

ifeq ($(PROJ_NAME), core0)
	plat-flags += -DCPU_LPC55S69JBD100_cm33_core0
else ifeq ($(PROJ_NAME), core1)
	plat-flags += -DCPU_LPC55S69JBD100_cm33_core1
endif