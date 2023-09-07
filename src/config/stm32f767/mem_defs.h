#ifndef __MEM_DEFS_H__
#define __MEM_DEFS_H__

/* Memories addresses and sizes*/
#define FLASH_MEM_AXIM                      0x08000000
#define FLASH_SIZE                          0x00200000

/* Flash memory sector in single-bank mode */
#define FLASH_MEM_AXIM_SECTORS
#define FLASH_MEM_AXIM_S0                   0x08000000
#define FLASH_MEM_AXIM_SIZE_S0              0x8000
#define FLASH_MEM_AXIM_S1                   FLASH_MEM_AXIM_S0+FLASH_MEM_AXIM_SIZE_S0
#define FLASH_MEM_AXIM_SIZE_S1              0x8000
#define FLASH_MEM_AXIM_S2                   FLASH_MEM_AXIM_S1+FLASH_MEM_AXIM_SIZE_S1
#define FLASH_MEM_AXIM_SIZE_S2              0x8000
#define FLASH_MEM_AXIM_S3                   FLASH_MEM_AXIM_S2+FLASH_MEM_AXIM_SIZE_S2
#define FLASH_MEM_AXIM_SIZE_S3              0x8000
#define FLASH_MEM_AXIM_S4                   FLASH_MEM_AXIM_S3+FLASH_MEM_AXIM_SIZE_S3
#define FLASH_MEM_AXIM_SIZE_S4              0x20000
#define FLASH_MEM_AXIM_S5                   FLASH_MEM_AXIM_S4+FLASH_MEM_AXIM_SIZE_S4
#define FLASH_MEM_AXIM_SIZE_S5              0x40000
#define FLASH_MEM_AXIM_S6                   FLASH_MEM_AXIM_S5+FLASH_MEM_AXIM_SIZE_S5
#define FLASH_MEM_AXIM_SIZE_S6              0x40000
#define FLASH_MEM_AXIM_S7                   FLASH_MEM_AXIM_S6+FLASH_MEM_AXIM_SIZE_S6
#define FLASH_MEM_AXIM_SIZE_S7              0x40000
#define FLASH_MEM_AXIM_S8                   FLASH_MEM_AXIM_S7+FLASH_MEM_AXIM_SIZE_S7
#define FLASH_MEM_AXIM_SIZE_S8              0x40000
#define FLASH_MEM_AXIM_S9                   FLASH_MEM_AXIM_S8+FLASH_MEM_AXIM_SIZE_S8
#define FLASH_MEM_AXIM_SIZE_S9              0x40000
#define FLASH_MEM_AXIM_S10                  FLASH_MEM_AXIM_S9+FLASH_MEM_AXIM_SIZE_S9
#define FLASH_MEM_AXIM_SIZE_S10             0x40000
#define FLASH_MEM_AXIM_S11                  FLASH_MEM_AXIM_S10+FLASH_MEM_AXIM_SIZE_S10
#define FLASH_MEM_AXIM_SIZE_S11             0x40000

#define FLASH_MEM_ITCM                      0x00200000

#define SRAM1                               0x20020000
#define SRAM1_SIZE                          0x5C000
#define SRAM2                               0x2007C000
#define SRAM2_SIZE                          0x4000

#define ITCM                                0x00000000
#define ITCM_SIZE                           0x4000
#define DTCM                                0x20000000
#define DTCM_SIZE                           0x20000

#endif  /* __MEM_DEFS_H__ */