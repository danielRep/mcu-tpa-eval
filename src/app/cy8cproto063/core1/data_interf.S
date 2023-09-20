.syntax     unified

#define N_REPT  25
#include "config.h"
.section    .text
.thumb
.thumb_func
.align      2
.global     data_interf
.type       data_interf, %function
/*----------------------------------------------------------------------------*/
data_interf:
    .rept N_REPT-1
    .align      2
    ldr r0, =CORE0_RAM_START
    b   1f
    ldr r1, [r0,#0x0]
    ldr r1, [r0,#0x40]
    ldr r1, [r0,#0x80]
    ldr r1, [r0,#0xC0]
    ldr r1, [r0,#0x100]
    ldr r1, [r0,#0x140]
    ldr r1, [r0,#0x180]
    ldr r1, [r0,#0x1C0]
1:
    .endr
    ldr r1, [r0,#0x200]
    ldr r1, [r0,#0x240]
    ldr r1, [r0,#0x280]
    ldr r1, [r0,#0x2C0]
    ldr r1, [r0,#0x300]
    ldr r1, [r0,#0x340]
    ldr r1, [r0,#0x380]
    ldr r1, [r0,#0x3C0]
    bx lr
.size data_interf, . - data_interf