# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Makefile Arguments
PLATFORM	:= stm32l476
TESTID		:= ctt
TESTSUITE	:= $(shell echo $(TESTID) | cut -c1-3)

################################################################################
# Toolchain Macros
ifndef CROSS_COMPILE
ifneq ($(MAKECMDGOALS), clean)
$(error CROSS_COMPILE (GNU Arm Embedded Toolchain) not set.			\
[usage] export CROSS_COMPILE=<gnu_arm_directory>/bin/arm-none-eabi-)
endif
endif

CC		:=	$(CROSS_COMPILE)gcc
LD		:=	$(CROSS_COMPILE)ld
OBJDUMP	:=	$(CROSS_COMPILE)objdump
OBJCOPY	:=	$(CROSS_COMPILE)objcopy
READELF	:=	$(CROSS_COMPILE)readelf
GDB		:=	$(CROSS_COMPILE)gdb
SIZE	:=	$(CROSS_COMPILE)size
SSTRIP	:=	$(CROSS_COMPILE)strip

FLASHTOOL	:= pyocd
FLASHOPTS	:=
ifeq ($(PLATFORM), lpc55s69)
	FLASHOPTS += -t LPC55S69
endif

################################################################################
# Top Directories
CUR_DIR		:= $(abspath .)
SRC_DIR		:= $(CUR_DIR)/src
APP_DIR		:= $(SRC_DIR)/app/$(PLATFORM)
LIB_DIR		:= $(SRC_DIR)/lib
CORE0_DIR	:= $(APP_DIR)/core0
CORE1_DIR	:= $(APP_DIR)/core1
ARCH_DIR	:= $(SRC_DIR)/arch
PLAT_DIR	:= $(SRC_DIR)/platform/$(PLATFORM)

BIN_DIR		:= $(CUR_DIR)/bin/$(PLATFORM)
BUILD_DIR	:= $(CUR_DIR)/build/$(PLATFORM)
CFG_DIR		:= $(SRC_DIR)/config

# Cfg Directories
CFG_INC		+= $(CFG_DIR)/$(PLATFORM)/$(TESTID)/
CFG_INC		+= $(CFG_DIR)/$(PLATFORM)/

# Generators
LDGEN_C		:= $(CFG_DIR)/ldscript.c
LDGEN_O		:= $(CFG_DIR)/$(PLATFORM)/$(TESTID)/gen_mem.ld

# Configuration setup
-include $(CFG_DIR)/$(PLATFORM)/$(TESTID)/config.mk

ifeq ($(MULTICORE), y)
	LD_VAR += -DMULTICORE
endif
ifeq ($(C0_DMA1), y)
	LD_VAR += -DC0_DMA1
endif
ifeq ($(C0_BOOTAGENT), y)
	LD_VAR += -DC0_BOOTAGENT
endif
ifeq ($(C1_BOOTAGENT), y)
	LD_VAR += -DC1_BOOTAGENT
endif

################################################################################
# Compilation Target
CORE0_ELF	:= $(BIN_DIR)/core0/core0.elf
CORE0_HEX	:= $(BIN_DIR)/core0/core0.hex
CORE0_LST	:= $(BIN_DIR)/core0/core0.lst
CORE1_ELF	:= $(BIN_DIR)/core1/core1.elf
CORE1_HEX	:= $(BIN_DIR)/core1/core1.hex
CORE1_LST	:= $(BIN_DIR)/core1/core1.lst

################################################################################
# Export all variables to submakes
export

################################################################################
# Default Makefile Rules
.PHONY: clean flash erase

all: linkerfile
	@echo "Building core0 app..."
	@$(MAKE) -C $(CORE0_DIR)
ifeq ($(MULTICORE), y)
	@$(MAKE) -C $(CORE1_DIR)
endif

clean:
	@echo "Cleaning projects..."
	@$(MAKE) -C $(CORE0_DIR) clean
ifeq ($(MULTICORE), y)
	@$(MAKE) -C $(CORE1_DIR) clean
endif

flash:
	@echo "Loading the core0 app..."
	@$(FLASHTOOL) flash $(CORE0_ELF) $(FLASHOPTS)
ifeq ($(MULTICORE), y)
	@echo "Loading the core1 app..."
	@$(FLASHTOOL) flash $(CORE1_ELF)
endif

erase:
	@echo "Erasing $(PLATFORM) memory..."
	@$(FLASHTOOL) erase --mass $(FLASHOPTS)

linkerfile:
	@echo "Creating LD defines..."
	@$(CC) -P -E $(addprefix -I, $(CFG_INC)) $(LDGEN_C) $(LD_VAR) -o $(LDGEN_O)
