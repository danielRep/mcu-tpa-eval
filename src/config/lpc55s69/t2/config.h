#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "mem_defs.h"

#define N_SAMPLES                           1000
#define WARMUP_HEAT                         100

/* TPA_MECH configuration */
#define N_MBBS                              5 /* MBBs */ + 1 /* Entry Point */

/* t2:
 * CORE0-CODE: FLASH_MEM
 * CORE0-DATA: SRAM0
 */

/* Core0 Memory Layout */
//CODE
#define CORE0_ROM_START                     FLASH_MEM
#define CORE0_ROM_LEN                       0x10000     //64KB
//DATA
#define CORE0_RAM_START                     SRAM0
#define CORE0_RAM_LEN                       0x8000      //32KB
//STACK
#define CORE0_STACK_SIZE                    0x800
//HEAP
#define CORE0_HEAP_SIZE                     0x400

#endif  /* __CONFIG_H__ */
