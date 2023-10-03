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
#ifdef MULTICORE
#include "cpu_id.s"
#endif

.syntax     unified
.arch       armv6-m

/*----------------------------------------------------------------------------*/
.section    .bootagent.boot, "ax"
.thumb
.thumb_func
.align      2
.global     reset_handler
.type       reset_handler, %function
.fnstart
/*----------------------------------------------------------------------------*/
reset_handler:
    /* Initialize stack pointer */
    ldr     r0, =__StackTop
    mov     sp, r0

#if (defined(C0_BOOTAGENT) || defined(C1_BOOTAGENT))
/* Boot Stage 0 --------------------------------------------------------------*/
_boot0_0:  /* Load CODE from LMA to VMA in FLASH */
    ldr     r0, =__text_lma     /* Source */
    ldr     r1, =__text_start   /* Destination */
    ldr     r2, =__etext_lma    /* End */

_boot0_1:
    ldr     r3, [r0], #4
    str     r3, [r1], #4
    cmp     r0, r2
    bcc     _boot0_1
#endif

/* Boot Stage 1 --------------------------------------------------------------*/
#ifdef MULTICORE
_boot1_0:
    GET_CPU_ID

_boot1_1:
    SET_UP_VECTOR_TBL
    KICKOFF_CORE1
#endif

/* Boot Stage 2 --------------------------------------------------------------*/
_boot2_0:
    /* Jump to app boot */
    b       Reset_Handler

    /* This point should never be reached */
    b       .
.fnend
.size    reset_handler, . - reset_handler

/* Force aligment of literal pool */
.align 2

/*----------------------------------------------------------------------------*/
.section .bootagent.vtb
.align   2
.global  _bootagent_vtb
/*----------------------------------------------------------------------------*/
_bootagent_vtb:
    .word __StackTop                    /*       MSP_S Initial Value          */
    .word reset_handler                 /*       Reset Handler                */
    .word nmi_handler                   /* -14   NMI Handler                  */
    .word hardfault_handler             /* -13   Hard Fault Handler           */
/* TODO: Check how to define interrupts */
.space 256
.size _bootagent_vtb, . - _bootagent_vtb

# -------------------------------------------------------------
.thumb_func
.align   2
.type    nmi_handler, %function
.fnstart
nmi_handler:
    b   .
.fnend
.size    nmi_handler, . - nmi_handler
# -------------------------------------------------------------
.thumb_func
.align   2
.type    hardfault_handler, %function
.fnstart
hardfault_handler:
    b   .
.fnend
.size    hardfault_handler, . - hardfault_handler
# -------------------------------------------------------------
