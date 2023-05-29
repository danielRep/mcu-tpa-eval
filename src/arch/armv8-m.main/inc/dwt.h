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

/* Comparator Functions */
#define DWT_FUNC_MATCH(x)           (x << 0)
#define DWT_FUNC_ACTION(x)          (x << 4)
#define DWT_FUNC_DATASIZE(x)        (x << 10)
#define DWT_FUNC_MATCHED            (1 << 24) // tells if the comparator was the reason for the exception
#define DWT_FUNC_ID(x)              (x << 27)

#define DWT_FUNC_MATCH_DISABLE                     DWT_FUNC_MATCH(0)
#define DWT_FUNC_MATCH_CYC_CNT                     DWT_FUNC_MATCH(1)
#define DWT_FUNC_MATCH_INST_ADDR                   DWT_FUNC_MATCH(2)
#define DWT_FUNC_MATCH_INST_ADDR_LIMIT             DWT_FUNC_MATCH(3)
#define DWT_FUNC_MATCH_DATA_ADDR                   DWT_FUNC_MATCH(4)
#define DWT_FUNC_MATCH_DATA_ADDR_WRITES            DWT_FUNC_MATCH(5)
#define DWT_FUNC_MATCH_DATA_ADDR_READS             DWT_FUNC_MATCH(6)
#define DWT_FUNC_MATCH_DATA_ADDR_LIMIT             DWT_FUNC_MATCH(7)
#define DWT_FUNC_MATCH_DATA_VALUE                  DWT_FUNC_MATCH(8)
#define DWT_FUNC_MATCH_DATA_VALUE_WRITES           DWT_FUNC_MATCH(9)
#define DWT_FUNC_MATCH_DATA_VALUE_READS            DWT_FUNC_MATCH(10)
#define DWT_FUNC_MATCH_LINKED_DATA_VALUE           DWT_FUNC_MATCH(11)
#define DWT_FUNC_MATCH_DATA_ADDR_WITH_VAL          DWT_FUNC_MATCH(12)
#define DWT_FUNC_MATCH_DATA_ADDR_WITH_VAL_WRITES   DWT_FUNC_MATCH(13)
#define DWT_FUNC_MATCH_DATA_ADDR_WITH_VAL_READS    DWT_FUNC_MATCH(14)

#define DWT_FUNC_ACTION_TRIGGER                    DWT_FUNC_ACTION(0)
#define DWT_FUNC_ACTION_DEBUG_EVENT                DWT_FUNC_ACTION(1)
#define DWT_FUNC_ACTION_VALUE_PACKET               DWT_FUNC_ACTION(2)
#define DWT_FUNC_ACTION_PC_PACKET                  DWT_FUNC_ACTION(3)

#define DWT_FUNC_DATASIZE_1_BYTE                   DWT_FUNC_DATASIZE(0)
#define DWT_FUNC_DATASIZE_2_BYTE                   DWT_FUNC_DATASIZE(1)
#define DWT_FUNC_DATASIZE_4_BYTE                   DWT_FUNC_DATASIZE(2)

#define DWT_COMP_FUNCTIONS                         DWT_FUNC_ID(31)

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
void dwt_init_counters(void);
void dwt_enable_counters(void);
void dwt_disable_counters(void);
void dwt_reset_counters(void);
uint32_t dwt_instruction_count(void);
uint32_t dwt_cpu_usage(void);
void dwt_compare_cyc_count(uint32_t cycnt);
void dwt_watch_data_addr(uint32_t addr);
void dwt_watch_data_address_range(uint32_t base_addr, uint32_t mem_size);
void dwt_disable_cycnt(void);
void dwt_enable_cycnt(void);
void dwt_reset_cycnt(void);
uint32_t dwt_read_cycnt(void);

#endif


