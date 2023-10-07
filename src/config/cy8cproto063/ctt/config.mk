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

C0_BENCH_APP	:= mont64
C0_FPM			:= y
C0_CLK_MAX		:= y
C1_INTRF_APP	:= ifi
C0_DMA0			:= y
C0_DMA1			:= y
