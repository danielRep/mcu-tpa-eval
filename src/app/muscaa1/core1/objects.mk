core1-objs-y += system_ARMCM33.o
core1-objs-y += platform_init.o

ifeq ($(C1_INTRF_APP), tpa_ifi)
	core1-objs-y += main_tpa_ifi.o
	core1-objs-y += cache_interf.o
else ifeq ($(C1_INTRF_APP), dai)
	core1-objs-y += main_dai.o
	core1-objs-y += data_interf.o
else ifeq ($(C1_INTRF_APP), ifi)
	core1-objs-y += main_ifi.o
	core1-objs-y += cache_interf.o
else
$(error C1 interf app "$(C1_INTRF_APP)" doesn't exist. Apps: main_ifi, main_dai, main_eval")
endif
