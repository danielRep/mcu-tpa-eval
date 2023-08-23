ifeq ($(TESTSUITE), sol)
core0-objs-y += main_solo.o
else ifeq ($(TESTSUITE), crf)
core0-objs-y += main_careful.o
else ifeq ($(TESTSUITE), slp)
core0-objs-y += main_sloppy.o
else ifeq ($(TESTSUITE), cat)
core0-objs-y += main_catastrophic.o
else ifeq ($(TESTSUITE), tpa)
core0-objs-y += main_tpa.o
endif
core0-objs-y += system_LPC55S69_cm33_core0.o
core0-objs-y += platform_init.o
ifneq (,$(filter y,$(C0_DMA0) $(C0_DMA1)))
core0-objs-y += dma_driver.o
endif