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

uint32_t dwt_instruction_count(void)
{
    return (DWT->CYCCNT - (DWT->CPICNT & 0xFF) - (DWT->EXCCNT & 0xFF) -         \
    (DWT->SLEEPCNT & 0xFF) - (DWT->LSUCNT & 0xFF) + (DWT->FOLDCNT & 0xFF));
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

// Return cpu usage in percentage
uint32_t dwt_cpu_usage(void)
{
    uint32_t cpu_usage = 0;

    /* Disable cycle counter and sleep counter */
    DWT->CTRL &= ~(DWT_CTRL_CYCCNTENA | DWT_CTRL_SLEEPEVTENA);

    cpu_usage = (DWT->CYCCNT / (DWT->CYCCNT + DWT->SLEEPCNT));

    DWT->CTRL |= (DWT_CTRL_CYCCNTENA | DWT_CTRL_SLEEPEVTENA);

    return (cpu_usage * 100);
}

void dwt_watch_data_address_range(uint32_t base_addr, uint32_t mem_size)
{

    __asm("ISB");
    DWT->COMP2 = base_addr;
    DWT->FUNCTION2 |= (DWT_FUNC_MATCH_DATA_ADDR | DWT_FUNC_ACTION_DEBUG_EVENT | DWT_FUNC_DATASIZE_1_BYTE);

    DWT->COMP3 = (base_addr + mem_size);
    DWT->FUNCTION3 |= (DWT_FUNC_MATCH_DATA_ADDR_LIMIT | DWT_FUNC_DATASIZE_1_BYTE);

    // Clear Debug Handler pending bit in case it is one
    DCB->DEMCR &= ~(DCB_DEMCR_MON_PEND_Msk);

    __asm("DSB");
}

void dwt_compare_cyc_count(uint32_t cycnt)
{
    // dwt_unlock();

    /*Reset CYCNT Val */
    DWT->CYCCNT = 0;

    DWT->CTRL &= ~(DWT_CTRL_CYCCNTENA);

    /* Cycle Count value to match in the comparator */
    DWT->COMP0 = cycnt;

    DWT->FUNCTION0 |= (DWT_FUNC_MATCH_CYC_CNT | DWT_FUNC_ACTION_DEBUG_EVENT | DWT_FUNC_DATASIZE_4_BYTE);

    DWT->CTRL |= (DWT_CTRL_CYCCNTENA);

    //    ENABLE_DEBUG_EX_S();
}

void dwt_watch_data_addr(uint32_t addr)
{
    // dwt_unlock();
    /*Use Comparator 2 */
    DWT->COMP2 = (uint32_t)addr;

    DWT->FUNCTION2 |= (DWT_FUNC_MATCH_DATA_ADDR | DWT_FUNC_ACTION_DEBUG_EVENT | DWT_FUNC_DATASIZE_4_BYTE);

    /*Enable Debug Monitor Exeption for Secure World*/
    //    ENABLE_DEBUG_EX_S();
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