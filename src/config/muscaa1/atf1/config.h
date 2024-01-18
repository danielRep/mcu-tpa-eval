#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "mem_defs.h"

#define N_SAMPLES                           1
#define WARMUP_HEAT                         100

/* Core0 Memory Layout */
//BOOTAGENT
#define CORE0_BOOTAGENT_START               FLASH_MEM
#define CORE0_BOOTAGENT_LEN                 0x8000 
//CODE
#define CORE0_ROM_START                     FLASH_MEM
#define CORE0_ROM_LEN                       0x10000 //64KB
//DATA
#define CORE0_RAM_START                     ISRAM1
#define CORE0_RAM_LEN                       0x8000 //32KB
//STACK
#define CORE0_STACK_SIZE                    0x2000
//HEAP
#define CORE0_HEAP_SIZE                     0x400
//TPA (RAM CODE)
#define CORE0_TPA_START                     ESRAM0
#define CORE0_TPA_LEN                       0x8000 //32KB

/* Core0 Memory Layout */
//CODE
#define CORE1_ROM_START                     FLASH_MEM+CORE0_ROM_LEN
#define CORE1_ROM_LEN                       0x10000     //64KB
//DATA
#define CORE1_RAM_START                     ISRAM3
#define CORE1_RAM_LEN                       0x8000 //32KB
//STACK
#define CORE1_STACK_SIZE                    0x800
//HEAP
#define CORE1_HEAP_SIZE                     0x400

#endif  /* __CONFIG_H__ */
