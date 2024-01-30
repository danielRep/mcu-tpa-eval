# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Project Name
PROJ_NAME := $(notdir $(shell pwd))

################################################################################
# Include Directories (generic)
-include $(PLAT_DIR)/platform.mk

ARCH_DIR  := $(ARCH_DIR)/$(ARCH)
BIN_DIR   := $(BIN_DIR)/$(PROJ_NAME)
BUILD_DIR := $(BUILD_DIR)/$(PROJ_NAME)
CMSIS_DIR := $(LIB_DIR)/cmsis
LIBC_DIR  := $(LIB_DIR)/libc/newlib
EMBE_DIR  := $(LIB_DIR)/embench
MEM_DIR   := $(CFG_DIR)/$(PLATFORM)
BENCH_DIR := $(CFG_DIR)/$(PLATFORM)/$(TESTID)
TPA_DIR   := $(LIB_DIR)/tpa_mech
ARTF_DIR  := $(LIB_DIR)/libartifapps

SRC_DIRS  := $(CORE0_DIR) $(ARCH_DIR) $(PLAT_DIR) $(LIB_DIR) $(CMSIS_DIR) $(LIBC_DIR) $(EMBE_DIR) $(ARTF_DIR)
INC_DIRS  := $(addsuffix /inc, $(SRC_DIRS)) $(MEM_DIR) $(BENCH_DIR)

# Source Files
-include $(addsuffix /objects.mk , $(SRC_DIRS))

objs-y += $(addprefix $(CORE0_DIR)/, $(core0-objs-y))
objs-y += $(addprefix $(ARCH_DIR)/, $(arch-objs-y))
objs-y += $(addprefix $(PLAT_DIR)/, $(plat-objs-y))
objs-y += $(addprefix $(LIBC_DIR)/, $(libc-objs-y))
objs-y += $(addprefix $(EMBE_DIR)/, $(embe-objs-y))
objs-y += $(addprefix $(ARTF_DIR)/, $(artifapps-objs-y))

ifdef ($(TPA))
objs-y += $(BENCH_DIR)/tmg.o
endif

# Dependencies
deps   += $(patsubst %.o,%.d,$(objs-y))
objs-y := $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(objs-y))

BUILD_DIRS  := $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS) $(INC_DIRS))
MKDIRS      := $(BIN_DIR) $(BUILD_DIR) $(BUILD_DIRS)

# Files for generation
ASM_DEFS_SRC := $(PLAT_DIR)/asm_defs.c
ASM_DEFS_HDR := $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(PLAT_DIR))/inc/asm_defs.h
INC_DIRS     += $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(PLAT_DIR))/inc

deps += $(ASM_DEFS_HDR).d
gens :=
gens += $(ASM_DEFS_HDR)

################################################################################
# Compilation Target
TARGET := $(BIN_DIR)/$(PROJ_NAME).elf

################################################################################
# Toolchain Flags
# CC Flags
CFLAGS := -$(OPTIM) -Wall $(plat-flags-c0) $(addprefix -I, $(INC_DIRS))
CFLAGS += -fcommon --specs=nano.specs -ffunction-sections -fdata-sections
CFLAGS += -DBENCHAPP=\"$(C0_BENCH_APP)\"
CFLAGS += -DINTRFAPP=\"$(C1_INTRF_APP)\"
CFLAGS += -DTESTID=\"$(TESTID)\"
CFLAGS += -DTESTSUITE=\"$(TESTSUITE)\"

ifeq ($(DEBUG), y)
CFLAGS += -g
endif

ifeq ($(C0_CLK_MAX), y)
CFLAGS += -DC0_CLK_MAX
endif

ifeq ($(MULTICORE), y)
CFLAGS += -DMULTICORE
endif

ifeq ($(C0_IC), y)
CFLAGS += -DC0_IC
endif

ifeq ($(C0_STATS), y)
CFLAGS += -DC0_STATS
endif

ifeq ($(C0_FPM), y)
CFLAGS += -DFPM
endif

ifneq ($(BUS_PRIO), n)
C0_PRIO := $(filter C0-%, $(BUS_PRIO))
C1_PRIO := $(filter C1-%,%,$(BUS_PRIO))
DMA0_PRIO := $(filter DMA0-%,%,$(BUS_PRIO))
DMA1_PRIO := $(filter DMA1-%,%,$(BUS_PRIO))

CFLAGS += -DBUS_PRIO
CFLAGS += $(if $(C0_PRIO),-DC0_PRIO=$(subst C0-,,$(C0_PRIO)))
CFLAGS += $(if $(C1_PRIO),-DC1_PRIO=$(subst C1-,,$(C1_PRIO)))
CFLAGS += $(if $(DMA0_PRIO),-DDMA0_PRIO=$(subst DMA0-,,$(DMA0_PRIO)))
CFLAGS += $(if $(DMA1_PRIO),-DDMA1_PRIO=$(subst DMA1-,,$(DMA1_PRIO)))
endif

ifeq ($(C1_BOOTAGENT), y)
CFLAGS += -DVTBL_BOOTAGENT
endif

ifeq ($(C0_BOOTAGENT), y)
CFLAGS += -DC0_BOOTAGENT
LDSCRIPT := $(BENCH_DIR)/$(PROJ_NAME)_bootagent.ld
else
LDSCRIPT := $(BENCH_DIR)/$(PROJ_NAME).ld
endif

ifeq ($(C0_DMA0), y)
CFLAGS += -DC0_DMA0
endif

ifeq ($(C0_DMA1), y)
CFLAGS += -DC0_DMA1
endif

# LD Flags
LDFLAGS  += -T$(LDSCRIPT) -L$(BENCH_DIR)
LDFLAGS  += -Xlinker -Map=$(basename $(TARGET)).map -Wl,--gc-sections
LDFLAGS  += -lm

# Library flags
ifeq ($(TPA), prof)
CFLAGS += -I$(TPA_DIR)/src/arch/armv8-m.main/inc -I$(TPA_DIR)/src/core/inc -I$(TPA_DIR)/src/config
CFLAGS += -DTPA_PROF -DCONFIG_LOGL=$(CONFIG_LOGL) -DCONFIG_PROF
LDFLAGS += -L $(TPA_DIR) -lutpaprof
TPA_CONFIG += CONFIG_PLAT=$(PLATFORM) CONFIG_PROF=y CONFIG_FILE=$(BENCH_DIR)/ CONFIG_PERFLOG=$(CONFIG_PERFLOG)
else ifeq ($(TPA), mech)
CFLAGS += -I$(TPA_DIR)/src/arch/armv8-m.main/inc -I$(TPA_DIR)/src/core/inc -I$(TPA_DIR)/src/config
CFLAGS += -I$(TPA_DIR)/src/plat/$(PLATFORM)/inc
CFLAGS += -DTPA_MECH -DCONFIG_LOGL=$(CONFIG_LOGL)
TPA_CONFIG += CONFIG_PLAT=$(PLATFORM) CONFIG_PROF=n CONFIG_FILE=$(BENCH_DIR)/ CONFIG_PERFLOG=$(CONFIG_PERFLOG)
LDFLAGS += -L $(TPA_DIR) -lutpamech
endif

################################################################################
# Default Makefile Rules
EMPTYTARGETS := clean

.PHONY: all clean

all: $(TARGET)

# Rule to create final binaries
$(TARGET): $(gens) $(objs-y) libs
	@echo "\nGenerating elf		$(patsubst $(CUR_DIR)/%, %, $@)"
	@$(CC) $(CFLAGS) $(objs-y) $(LDFLAGS) -o $@
	@echo "Generating hex		$(patsubst $(CUR_DIR)/%, %, $(basename $@).hex)"
	@$(OBJCOPY) -O ihex $@ $(basename $@).hex
	@echo "Generating binary	$(patsubst $(CUR_DIR)/%, %, $(basename $@).bin)"
	@$(OBJCOPY) -O binary $@ $(basename $@).bin
	@echo "\n$(PROJ_NAME) size table"
	@$(SIZE) $@
	@$(OBJDUMP) -S --wide $@ > $(basename $@).asm
	@$(READELF) -a --wide $@ > $(basename $@).txt
	@$(OBJDUMP) --all-headers --demangle --disassemble --file-headers --wide \
				--visualize-jumps -D $@ > $(basename $@).lst

# Rule to compile sources
$(objs-y):
	@echo "Compiling source	$(patsubst $(CUR_DIR)/%, %, $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to create dependencies
$(BUILD_DIR)/%.d : $(SRC_DIR)/%.[c,S]
	@echo "Creating dependency	$(patsubst $(CUR_DIR)/%, %, $@)"
	@$(CC) -MM -MG -MT "$(patsubst %.d, %.o, $@) $@" $(CFLAGS) $< > $@

#avoid including .d files during empty targets
ifeq (,$(filter $(EMPTYTARGETS), $(MAKECMDGOALS)))
-include $(deps)
endif

libs:
ifeq ($(TPA), prof)
	@echo "Generating tpa profiler library $(TPA_DIR)/libutpaprof.a"
	@make -C $(TPA_DIR) $(TPA_CONFIG)
else ifeq ($(TPA), mech)
	@echo "Generating tpa mechanism library $(TPA_DIR)/libutpamech.a"
	@make -C $(TPA_DIR) $(TPA_CONFIG)
endif

# Rule to erase directories
clean:
	@echo "Erasing $(PROJ_NAME) directories..."
	@-rm -rf $(BUILD_DIR)
	@-rm -rf $(BIN_DIR)
	@make -C $(TPA_DIR) $(TPA_CONFIG) clean CONFIG_FILE=$(BENCH_DIR)/

# Rule to generate assembly macros
ifneq ($(wildcard $(ASM_DEFS_SRC)),)
$(ASM_DEFS_HDR): $(ASM_DEFS_SRC)
	@echo "Generating header	$(patsubst $(CUR_DIR)/%, %, $@)"
	@$(CC) -S $(CFLAGS) $< -o - | awk '($$1 == "->") { print "#define " $$2 " " $$3 }' > $@

$(ASM_DEFS_HDR).d: $(ASM_DEFS_SRC)
	@echo "Creating dependency	$(patsubst $(CUR_DIR)/%, %, $(patsubst %.d,%, $@))"
	@$(CC) -MM -MT "$(patsubst %.d,%, $@)" $(addprefix -I, $(INC_DIRS)) $< > $@
endif


# Rules after the read-phase and before the target-phase
.SECONDEXPANSION:

$(objs-y) $(deps) $(TARGET) $(gens): | $$(@D)

# Rule to create directories during the second expansion
$(MKDIRS):
	@echo "Creating directories	$(patsubst $(CUR_DIR)/%, %, $@)"
	@mkdir -p $@
