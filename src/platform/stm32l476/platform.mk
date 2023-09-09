# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Architecture Definition
ARCH	:=	armv7e-m

################################################################################
# CPU Definition
CPU		:=	cortex-m4
ENDIAN	:=	little-endian
THUMB	:=	thumb
ABI		:=	soft
FPU		:=	fpv4-sp-d16

################################################################################
# Exporting Flags
plat-flags-c0 = -march=$(ARCH) -mcpu=$(CPU) -m$(THUMB) 		\
			 -m$(ENDIAN) -mfloat-abi=$(ABI) -mfpu=$(FPU)	\
			 -DSTM32L476xx
