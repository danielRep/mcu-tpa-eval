.syntax     unified

#define N_REPT  512

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
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
1:
    .endr
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    bx lr
.size fill_cache, . - fill_cache
