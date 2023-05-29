ifeq ($(C0_BENCH_APP), statemate)
	embe-objs-y += libstatemate.o
else ifeq ($(C0_BENCH_APP), edn)
	embe-objs-y += libedn.o
else ifeq ($(C0_BENCH_APP), minver)
	embe-objs-y += libminver.o
else ifeq ($(C0_BENCH_APP), mont64)
	embe-objs-y += mont64.o
else ifeq ($(C0_BENCH_APP), crc_32)
	embe-objs-y += crc_32.o beebsc.o
else ifeq ($(C0_BENCH_APP), nsichneu)
	embe-objs-y += libnsichneu.o
else ifeq ($(C0_BENCH_APP), huffbench)
	embe-objs-y += libhuffbench.o beebsc.o
else ifeq ($(C0_BENCH_APP), matmult-int)
	embe-objs-y += matmult-int.o
else ifeq ($(C0_BENCH_APP), nbody)
	embe-objs-y += nbody.o
	LDFLAGS += -lm
endif
