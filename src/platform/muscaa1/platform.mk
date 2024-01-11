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
C0_CPU		:=	cortex-m33+nodsp
C0_ENDIAN	:=	little-endian
C0_THUMB	:=	thumb
C0_ABI		:=	softfp
C0_FPU		:=	fpv5-sp-d16

C1_CPU		:=	cortex-m33
C1_ENDIAN	:=	little-endian
C1_THUMB	:=	thumb
C1_ABI		:=	hard
C1_FPU		:=	fpv5-sp-d16

################################################################################
# Exporting Flags
plat-flags-c0 = -mcpu=$(C0_CPU) -m$(C0_THUMB) -m$(C0_ENDIAN) -mfpu=$(C0_FPU) \
				-mfloat-abi=$(C0_ABI) -u _printf_float -DARMCM33_DSP_FP_TZ

plat-flags-c1 = -mcpu=$(C1_CPU) -m$(C1_THUMB) -m$(C1_ENDIAN) -mfpu=$(C1_FPU)
				-mfloat-abi=$(C1_ABI) -DARMCM33_DSP_FP_TZ
