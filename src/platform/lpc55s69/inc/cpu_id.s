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
    /* CPU1 has no MPU, therefore MPU->TYPE reg should be read-as-zero. That's
     * how we distinguish between CPU0 and CPU1 */
    ldr     r0, =MPU_TYPE
    ldr     r1, [r0]
    mov     r2, MPU_TYPE_DREGION
    and     r1, r2
    cmp     r1, #0
    beq     _boot2_0
.endm

.macro  SET_UP_VECTOR_TBL
    /* Update CPU1 vector table in SYSCON->CPUBOOT reg */
#ifdef VTBL_BOOTAGENT
    ldr     r1, =CORE1_BOOTAGENT_START
#else
    ldr     r1, =CORE1_ROM_START
#endif
    ldr     r0, =SYSCON_BASE
    str     r1, [r0, CPUBOOT_OFF]
.endm

.macro  KICKOFF_CORE1
    /* Enable CPU1 in SYSCON->CPUCFG reg */
    ldr     r1, [r0, CPUCFG_OFF]
    orr     r2, r1, SYSCON_CPUCFG_CPU1ENABLE_MASK
    str     r2, [r0, CPUCFG_OFF]
    /* Enable CPU1 clock and release from reset in SYSCON->CPUCTRL reg */
    ldr     r1, [r0, CPUCTRL_OFF]
    mov     r2, #0xC0C4
    mov     r4, r2, lsl #16
    orr     r3, r4, r1
    orr     r3, r3, SYSCON_CPUCTRL_CPU1RSTEN_MASK
    orr     r3, r3, SYSCON_CPUCTRL_CPU1CLKEN_MASK
    str     r3, [r0, CPUCTRL_OFF]
    mov     r1, SYSCON_CPUCTRL_CPU1RSTEN_MASK
    orr     r1, r1, SYSCON_CPUCTRL_CPU1CLKEN_MASK
    bic     r4, r4, r1
    orr     r4, SYSCON_CPUCTRL_CPU1CLKEN_MASK
    str     r4, [r0, CPUCTRL_OFF]
.endm
