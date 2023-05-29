core1-objs-y += system_LPC55S69_cm33_core1.o
core1-objs-y += platform_init.o

ifeq ($(C1_INTRF_APP), ifi)
	core1-objs-y += main_ifi.o
	core1-objs-y += cache_interf.o
else ifeq ($(C1_INTRF_APP), dai)
	core1-objs-y += main_dai.o
else
$(error C1 interf app "$(C1_INTRF_APP)" doesn't exist. Apps: main_ifi, main_dai")
endif
