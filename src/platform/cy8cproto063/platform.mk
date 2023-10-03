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
	plat-flags-c0 += -D$(DEVICE) -DCOMPONENT_APP_CY8CPROTO_063_BLE -DCOMPONENT_BLESS_IPC -DCOMPONENT_CAT1 -DCOMPONENT_CAT1A -DCOMPONENT_CM0P -DCOMPONENT_CM0P_0 -DCOMPONENT_Debug -DCOMPONENT_GCC_ARM -DCOMPONENT_MW_CAT1CM0P -DCOMPONENT_MW_CMSIS -DCOMPONENT_MW_CORE_LIB -DCOMPONENT_MW_CORE_MAKE -DCOMPONENT_MW_MTB_HAL_CAT1 -DCOMPONENT_MW_MTB_PDL_CAT1 -DCOMPONENT_MW_RECIPE_MAKE_CAT1A -DCOMPONENT_PSOC6_01 -DCOMPONENT_SOFTFP -DCORE_NAME_CM0P_0=1 -DCYBLE_416045_02_device -DCY_APPNAME_proj_cm0p -DCY_CORTEX_M4_APPL_ADDR=CY_FLASH_BASE+0x4400U -DCY_SUPPORTS_DEVICE_VALIDATION -DCY_TARGET_BOARD=APP_CY8CPROTO_063_BLE -DCY_USING_HAL -DDEBUG -DTARGET_APP_CY8CPROTO_063_BLE
else ifeq ($(PROJ_NAME), core1)
	plat-flags-c1 += -D$(DEVICE) -DCOMPONENT_APP_CY8CPROTO_063_BLE -DCOMPONENT_BLESS_IPC -DCOMPONENT_CAT1 -DCOMPONENT_CAT1A -DCOMPONENT_CM4 -DCOMPONENT_CM4_0 -DCOMPONENT_Debug -DCOMPONENT_GCC_ARM -DCOMPONENT_MW_CAT1CM0P -DCOMPONENT_MW_CMSIS -DCOMPONENT_MW_CORE_LIB -DCOMPONENT_MW_CORE_MAKE -DCOMPONENT_MW_MTB_HAL_CAT1 -DCOMPONENT_MW_MTB_PDL_CAT1 -DCOMPONENT_MW_RECIPE_MAKE_CAT1A -DCOMPONENT_PSOC6_01 -DCOMPONENT_SOFTFP -DCORE_NAME_CM4_0=1 -DCYBLE_416045_02_device -DCY_APPNAME_proj_cm4 -DCY_SUPPORTS_DEVICE_VALIDATION -DCY_TARGET_BOARD=APP_CY8CPROTO_063_BLE -DCY_USING_HAL -DDEBUG -DTARGET_APP_CY8CPROTO_063_BLE
endif

