#ifndef __MEM_DEFS_H__
#define __MEM_DEFS_H__

/* Memories addresses and sizes*/

#define FLASH_MEM                           0x00000000      //FLASH_MEM naming to avoid redefinitions
#define FLASH_SIZE                          0x9D800         //630KiB (last 10KiB are reserved)

#define SRAMX                               0x04000000
#define SRAMX_SIZE                          0x8000          //32KiB

#define SRAM0                               0x20000000
#define SRAM1                               0x20010000
#define SRAM2                               0x20020000
#define SRAM3                               0x20030000
#define SRAM_SIZE                           0x10000         //64KiB

#define SRAM4                               0x20040000
#define SRAM4_SIZE                          0x4000          //16KiB
#endif  /* __MEM_DEFS_H__ */