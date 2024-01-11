#ifndef __DWT_H__
#define __DWT_H__

#include "content_eval.h"
#include "platform_config.h"

/*
*  Used to unlock write access to the DWT tracing unit
*  First it is needed to enable tracing in the DEMCR Register
*/
#define DWT_LAR_UNLOCK              (0xC5ACCE55UL)

/* Counters */
#define DWT_CTRL_CYCCNTENA          (1 << 0)
#define DWT_CTRL_CPIEVTENA          (1 << 17)
#define DWT_CTRL_EXCEVTENA          (1 << 18)
#define DWT_CTRL_SLEEPEVTENA        (1 << 19)
#define DWT_CTRL_LSUEVTENA          (1 << 20)
#define DWT_CTRL_FOLDEVTENA         (1 << 21)

#define DWT_ENABLE_ALL_CNTRS        (DWT_CTRL_CYCCNTENA | DWT_CTRL_CPIEVTENA   |\
                                     DWT_CTRL_EXCEVTENA | DWT_CTRL_SLEEPEVTENA |\
                                     DWT_CTRL_LSUEVTENA | DWT_CTRL_FOLDEVTENA)

#define DWT_DISABLE_ALL_CNTRS       ~(DWT_ENABLE_ALL_CNTRS)



/*
! DWT Comparator functions
*      Comp 0   ID Bits = 0b01011 - Cycle Counter, Instruction Address, Data Address and Data Address With Value
*      Comp 1   ID Bits = 0b11010 - Instruction Address, Instruction Address Limit, Data Address, Data Address Limit, and Data Address With Value.
*      Comp 2   ID Bits = 0b01010 - Instruction Address, Data Address, and Data Address With Value.
*      Comp 3   ID Bits = 0b11110 - Instruction Address, Instruction Address Limit, Data Address, Data Address Limit, Data value, Linked Data Value, and Data Address With Value.
*/

/*
! Note about the comparators
*   DWT_COMPn holds a value for the comparison.
*   DWT_FUNCTIONn defines the operation of the comparator.
*   Can be used as a single comparator for instruction address matching or data address matching
*                                           OR
*  in linked pairs for instruction address range matching or data address range matching.
*/

/* Functions Definition */
void dwt_unlock(void);
void dwt_reset_counters(void);
void dwt_init_counters(void);
void dwt_disable_counters(void);
void dwt_enable_counters(void);
uint32_t dwt_read_cycnt(void);
void dwt_disable_cycnt(void);
void dwt_enable_cycnt(void);
void dwt_reset_cycnt(void);

#endif
