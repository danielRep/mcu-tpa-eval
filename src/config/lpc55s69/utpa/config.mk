# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# TPA Mechanism Configuration
TPA				:= mech
CONFIG_DEBUG	:= n
CONFIG_LOGL		:= 0
CONFIG_PERFLOG	:= y

# Platform Configuration
MULTICORE		:= y
C0_BENCH_APP	:= wikisort
C0_BOOTAGENT	:= n
C0_CLK_MAX		:= y
C0_STATS		:= n
C0_FPM			:= y
C1_INTRF_APP	:= ifi

# Toolchain Configuration
DEBUG			:= y
OPTIM			:= O2
