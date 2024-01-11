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
#include <asm_defs.h>
#include "config.h"
#include "sse200_regs.h"

.macro   GET_CPU_ID
    ldr     r0, =CPUIDT_BASE_S
    ldr     r1, [r0, CPUIDT_ID_OFF]
    cmp     r1, #0
    bne     _boot2_0
.endm

.macro  SET_UP_VECTOR_TBL
    ldr     r0, =SCR_BASE_S
#ifdef VTBL_BOOTAGENT
    ldr     r1, =CORE1_BOOTAGENT_START
#else
    ldr     r1, =CORE1_ROM_START
#endif
    str     r1, [r0, INITSVTOR1_OFF]
.endm

.macro  KICKOFF_CORE1
    mov     r1, #0
    str     r1, [r0, CPUWAIT_OFF]
.endm
