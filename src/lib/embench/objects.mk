ifeq ($(C0_BENCH_APP), statemate)
	embe-objs-y += libstatemate.o
else ifeq ($(C0_BENCH_APP), edn)
	embe-objs-y += libedn.o
else ifeq ($(C0_BENCH_APP), minver)
	embe-objs-y += libminver.o
else ifeq ($(C0_BENCH_APP), mont64)
	embe-objs-y += mont64.o
else ifeq ($(C0_BENCH_APP), crc32)
	embe-objs-y += crc_32.o beebsc.o
else ifeq ($(C0_BENCH_APP), nsichneu)
	embe-objs-y += libnsichneu.o
else ifeq ($(C0_BENCH_APP), huffbench)
	embe-objs-y += libhuffbench.o beebsc.o
else ifeq ($(C0_BENCH_APP), matmult-int)
	embe-objs-y += matmult-int.o
else ifeq ($(C0_BENCH_APP), md5)
	embe-objs-y += md5.o beebsc.o
else ifeq ($(C0_BENCH_APP), nettle-aes)
	embe-objs-y += nettle-aes.o
else ifeq ($(C0_BENCH_APP), sglib-combined)
	embe-objs-y += combined.o beebsc.o
else ifeq ($(C0_BENCH_APP), nettle-sha256)
	embe-objs-y += nettle-sha256.o
else ifeq ($(C0_BENCH_APP), picojpeg)
	embe-objs-y += picojpeg_test.o libpicojpeg.o
else ifeq ($(C0_BENCH_APP), primecount)
	embe-objs-y += primecount.o
else ifeq ($(C0_BENCH_APP), slre)
	embe-objs-y += libslre.o
else ifeq ($(C0_BENCH_APP), ud)
	embe-objs-y += libud.o
else ifeq ($(C0_BENCH_APP), wikisort)
	embe-objs-y += libwikisort.o beebsc.o
else ifeq ($(C0_BENCH_APP), st)
	embe-objs-y += libst.o
	LDFLAGS += -lm
else ifeq ($(C0_BENCH_APP), nbody)
	embe-objs-y += nbody.o
	LDFLAGS += -lm
else ifeq ($(C0_BENCH_APP), tarfind)
	embe-objs-y += tarfind.o beebsc.o
else ifeq ($(C0_BENCH_APP), qrduino)
	embe-objs-y += qrencode.o qrframe.o qrtest.o beebsc.o
else ifeq ($(C0_BENCH_APP), cubic)
	embe-objs-y += libcubic.o basicmath_small.o
endif
