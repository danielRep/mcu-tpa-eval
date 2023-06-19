ifeq ($(C0_ARTIF_APP), artifapp1)
	C0_BENCH_APP := artifapp1
	artifapps-objs-y += artifapp1.o
else ifeq ($(C0_ARTIF_APP), artifapp2)
	C0_BENCH_APP := artifapp2
	artifapps-objs-y += artifapp2.o
endif
