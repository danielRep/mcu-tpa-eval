#include "dwt.h"
#include <stdio.h>

void dwt_unlock(void)
{
    DCB->DHCSR |= 0;

    /* Enable DWT and ITM on DCB */
    DCB->DEMCR |= DCB_DEMCR_TRCENA_Msk;

    // Enabling this bit makes the system stall while running coremark
    //   DCB->DEMCR |=  DCB_DEMCR_MON_STEP;

    /* Unlock access to DWT */
    ITM->LAR = DWT_LAR_UNLOCK;
}

void dwt_reset_counters(void)
{
    /* Reset all counters */
    DWT->CYCCNT = 0;
    DWT->CPICNT = 0;
    DWT->EXCCNT = 0;
    DWT->SLEEPCNT = 0;
    DWT->LSUCNT = 0;
    DWT->FOLDCNT = 0;
}

void inline dwt_disable_counters(void)
{
    /* Disable all DWT counters */
    DWT->CTRL &= ~DWT_ENABLE_ALL_CNTRS;
}

void inline dwt_enable_counters(void)
{
    /* Enable all DWT counters */
    DWT->CTRL |= DWT_ENABLE_ALL_CNTRS;
}

uint32_t dwt_read_cycnt(void)
{
    return (DWT->CYCCNT);
}

void dwt_init_counters(void)
{
    dwt_unlock();

    dwt_disable_counters();

    dwt_reset_counters();

    dwt_enable_counters();
}

void inline dwt_enable_cycnt(void)
{
    DWT->CTRL |= DWT_CTRL_CYCCNTENA;
}

void inline dwt_disable_cycnt(void)
{
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA;
}

void inline dwt_reset_cycnt(void)
{
    DWT->CYCCNT = 0;
}