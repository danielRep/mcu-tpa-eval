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
#include "sse200_regs.h"

#define DEFINE_OFFSET(SYMBOL, STRUCT, FIELD)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(offsetof(STRUCT, FIELD)))

#define DEFINE_SIZE(SYMBOL, TYPE)  \
    asm volatile("\n-> " #SYMBOL " %0 \n" : : "i"(sizeof(TYPE)))


void sse200_cpuidt_regs_defines() __attribute__((used));
void sse200_cpuidt_regs_defines()
{
    DEFINE_OFFSET(CPUIDT_ID_OFF, CPUIDT_type, CPU_IDENTITY);
}

void sse200_scr_regs_defines() __attribute__((used));
void sse200_scr_regs_defines()
{
    DEFINE_OFFSET(INITSVTOR0_OFF, SCR_type, INITSVTOR0);
    DEFINE_OFFSET(INITSVTOR1_OFF, SCR_type, INITSVTOR1);
    DEFINE_OFFSET(CPUWAIT_OFF, SCR_type, CPUWAIT);
}
