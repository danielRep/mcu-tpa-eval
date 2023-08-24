# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# Configuration setup
MULTICORE		:= y
DEBUG			:= y
OPTIM			:= O2
C0_BENCH_APP	:= wikisort
C0_FPM			:= y
C0_CLK_MAX		:= y
BUS_PRIO		:= C0-2 C1-3 DMA0-3 DMA1-3
C1_INTRF_APP	:= dai
C0_DMA0			:= y
C0_DMA1			:= y
