#add target object files for the tpa
ifeq ($(TPA), prof)
	tpa-objs-y += $(addprefix $(TPA_DIR)/, tpa_prof.o)
else ifeq ($(TPA), mech)
	tpa-objs-y += $(addprefix $(TPA_DIR)/, tpa_mech.o)
endif
tpa-objs-y += $(addprefix $(TPA_DIR)/, cyc_cnt.o)
tpa-objs-y += $(addprefix $(BENCH_DIR)/, tpa_cfg.o)