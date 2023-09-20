#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "mem_defs.h"

#define N_SAMPLES                           1000

/* Core0 Memory Layout */
//CODE
#define CORE0_ROM_START                     FLASH_MEM
#define CORE0_ROM_LEN                       FLASH_MEM_SIZE     //64KB
//DATA
#define CORE0_RAM_START                     SRAM_MEM
#define CORE0_RAM_LEN                       SRAM_MEM_SIZE      //32KB
//STACK
#define CORE0_STACK_SIZE                    0x2000
//HEAP
#define CORE0_HEAP_SIZE                     0x400

#endif  /* __CONFIG_H__ */
