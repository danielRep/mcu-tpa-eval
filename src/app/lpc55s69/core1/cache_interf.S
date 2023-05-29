.syntax     unified

#define N_REPT  1024

.section    .text
.thumb
.thumb_func
.align      2
.global     fill_cache
.type       fill_cache, %function
/*----------------------------------------------------------------------------*/
fill_cache:
    .rept N_REPT-1
    .align      2
    b   1f
    nop
    nop
    nop
    nop
    nop
    nop
    nop
1:
    .endr
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    bx lr
.size fill_cache, . - fill_cache
