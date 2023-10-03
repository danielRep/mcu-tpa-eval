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
#include "platform_base_addrs.h"

.macro   GET_CPU_ID
    /* Read CPUSS_ID register */
    ldr     r0, =CPUSS_BASE
    ldr     r1, =CPUSS_ID
    ldr     r2, [r0, r1]
    lsrs    r2, r2, #CPUSS_V2_IDENTITY_MS_Pos
    cmp     r2, #0
    bne     _boot2_0
.endm

.macro  SET_UP_VECTOR_TBL
    /* Read CPU1 vector table */
#ifdef VTBL_BOOTAGENT
    ldr     r0, =CORE1_BOOTAGENT_START
#else
    ldr     r0, =CORE1_ROM_START
#endif
.endm

.macro  KICKOFF_CORE1
    /* Enable CPU1 */
    bl      Cy_SysEnableCM4
.endm
