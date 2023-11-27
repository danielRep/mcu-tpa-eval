# Authors: Daniel Oliveira <daniel.oliveira@dei.uminho.pt>
#          Sandro Pinto    <sandro.pinto@dei.uminho.pt>
#
# contention-eval is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by
# the Free Software Foundation.

################################################################################
# TPA Mechanism Configuration
TPA				:= mech
MULTICORE		:= y
C0_BENCH_APP	:= huffbench
FUNCTION_FONS	
LOGGING			:= y
LOGLEVEL		:= 0

# System Configuration setup
DEBUG			:= y
OPTIM			:= O2
C0_FPM			:= y
C0_CLK_MAX		:= y
BUS_PRIO		:= n
C1_INTRF_APP	:= ifi
