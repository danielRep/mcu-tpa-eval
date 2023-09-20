#include "systick.h"

void systick_reset_counter(void)
{
    /* Reset counter */
    SysTick->CTRL = 0x0;
    SysTick->VAL = 0x0;
    SysTick->LOAD = (uint32_t)(0xFFFFFF - 1); //max counter value
}

void inline systick_disable_counter(void)
{
    /* Disable all DWT counters */
    SysTick->CTRL &= ~(0x1);
}

void inline systick_enable_counter(void)
{
    /* Enable all DWT counters */
    SysTick->CTRL |= 0x1;
}

uint32_t systick_read_counter(void)
{
    return (SysTick->VAL);
}
