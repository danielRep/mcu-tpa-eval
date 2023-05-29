/*
 * Authors:
 *      Daniel Oliveira <daniel.oliveira@tango-project.org>
 *      Sandro Pinto <sandro.pinto@tango-project.org>
 *
 * contention-eval is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 */
#include "content_eval.h"
#ifdef CPU_LPC55S69JBD100_cm33_core0
#include "LPC55S69_cm33_core0.h"
#endif

#define DEFINE_OFFSET(SYMBOL, STRUCT, FIELD)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(offsetof(STRUCT, FIELD)))

#define DEFINE_SIZE(SYMBOL, TYPE)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(sizeof(TYPE)))

#ifdef CPU_LPC55S69JBD100_cm33_core0
void syscon_regs_defines() __attribute__((used));
void syscon_regs_defines()
{
    DEFINE_OFFSET(CPUCFG_OFF, SYSCON_Type, CPUCFG);
    DEFINE_OFFSET(CPUCTRL_OFF, SYSCON_Type, CPUCTRL);
    DEFINE_OFFSET(CPUBOOT_OFF, SYSCON_Type, CPBOOT);
}
#endif