ifeq ($(C0_ARTIF_APP), statemate)
	artifapps-objs-y += artifapp1.o
else ifeq ($(C0_ARTIF_APP), edn)
	artifapps-objs-y += artifapp2.o
endif
