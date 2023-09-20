/**************************************************************************//**
 * @file     startup_ARMCM0plus.S
 * @brief    CMSIS-Core(M) Device Startup File for Cortex-M0plus Device
 * @version  V2.2.0
 * @date     26. May 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

                .syntax  unified
                .arch    armv6-m

                .section .vectors
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                .long    __StackTop                         /*     Top of Stack */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVC_Handler                        /*  -5 SVCall Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Interrupts */
                .long Interrupt0_Handler     /* 16 */
                .long Interrupt1_Handler     /* 17 */
                .long Interrupt2_Handler     /* 18 */
                .long Interrupt3_Handler     /* 19 */
                .long Interrupt4_Handler     /* 20 */
                .long Interrupt5_Handler     /* 21 */
                .long Interrupt6_Handler     /* 22 */
                .long Interrupt7_Handler     /* 23 */
                .long Interrupt8_Handler     /* 24 */
                .long Interrupt9_Handler     /* 25 */
                .long Interrupt10_Handler    /* 26 */
                .long Interrupt11_Handler    /* 27 */
                .long Interrupt12_Handler    /* 28 */
                .long Interrupt13_Handler    /* 29 */
                .long Interrupt14_Handler    /* 30 */
                .long Interrupt15_Handler    /* 31 */
                .long Interrupt16_Handler    /* 32 */
                .long Interrupt17_Handler    /* 33 */
                .long Interrupt18_Handler    /* 34 */
                .long Interrupt19_Handler    /* 35 */
                .long Interrupt20_Handler    /* 36 */
                .long Interrupt21_Handler    /* 37 */
                .long Interrupt22_Handler    /* 38 */
                .long Interrupt23_Handler    /* 39 */
                .long Interrupt24_Handler    /* 40 */
                .long Interrupt25_Handler    /* 41 */
                .long Interrupt26_Handler    /* 42 */
                .long Interrupt27_Handler    /* 43 */
                .long Interrupt28_Handler    /* 44 */
                .long Interrupt29_Handler    /* 45 */
                .long Interrupt30_Handler    /* 46 */
                .long Interrupt31_Handler    /* 47 */

__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                bl       SystemInit

                ldr      r4, =__copy_table_start__
                ldr      r5, =__copy_table_end__

.L_loop0:
                cmp      r4, r5
                bge      .L_loop0_done
                ldr      r1, [r4]                /* source address */
                ldr      r2, [r4, #4]            /* destination address */
                ldr      r3, [r4, #8]            /* word count */
                lsls     r3, r3, #2              /* byte count */

.L_loop0_0:
                subs     r3, #4                  /* decrement byte count */
                blt      .L_loop0_0_done
                ldr      r0, [r1, r3]
                str      r0, [r2, r3]
                b        .L_loop0_0

.L_loop0_0_done:
                adds     r4, #12
                b        .L_loop0

.L_loop0_done:

                ldr      r3, =__zero_table_start__
                ldr      r4, =__zero_table_end__

.L_loop2:
                cmp      r3, r4
                bge      .L_loop2_done
                ldr      r1, [r3]                /* destination address */
                ldr      r2, [r3, #4]            /* word count */
                lsls     r2, r2, #2              /* byte count */
                movs     r0, 0

.L_loop2_0:
                subs     r2, #4                  /* decrement byte count */
                blt      .L_loop2_0_done
                str      r0, [r1, r2]
                b        .L_loop2_0
.L_loop2_0_done:

                adds     r3, #8
                b        .L_loop2
.L_loop2_done:

                bl       _start

                .fnend
                .size    Reset_Handler, . - Reset_Handler

/* The default macro is not used for HardFault_Handler
 * because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/* Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm


/* Default exception/interrupt handler */

                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  Interrupt0_Handler
                Set_Default_Handler  Interrupt1_Handler
                Set_Default_Handler  Interrupt2_Handler
                Set_Default_Handler  Interrupt3_Handler
                Set_Default_Handler  Interrupt4_Handler
                Set_Default_Handler  Interrupt5_Handler
                Set_Default_Handler  Interrupt6_Handler
                Set_Default_Handler  Interrupt7_Handler
                Set_Default_Handler  Interrupt8_Handler
                Set_Default_Handler  Interrupt9_Handler
                Set_Default_Handler  Interrupt10_Handler
                Set_Default_Handler  Interrupt11_Handler
                Set_Default_Handler  Interrupt12_Handler
                Set_Default_Handler  Interrupt13_Handler
                Set_Default_Handler  Interrupt14_Handler
                Set_Default_Handler  Interrupt15_Handler
                Set_Default_Handler  Interrupt16_Handler
                Set_Default_Handler  Interrupt17_Handler
                Set_Default_Handler  Interrupt18_Handler
                Set_Default_Handler  Interrupt19_Handler
                Set_Default_Handler  Interrupt20_Handler
                Set_Default_Handler  Interrupt21_Handler
                Set_Default_Handler  Interrupt22_Handler
                Set_Default_Handler  Interrupt23_Handler
                Set_Default_Handler  Interrupt24_Handler
                Set_Default_Handler  Interrupt25_Handler
                Set_Default_Handler  Interrupt26_Handler
                Set_Default_Handler  Interrupt27_Handler
                Set_Default_Handler  Interrupt28_Handler
                Set_Default_Handler  Interrupt29_Handler
                Set_Default_Handler  Interrupt30_Handler
                Set_Default_Handler  Interrupt31_Handler


                .end
