#ifndef __MEM_DEFS_H__
#define __MEM_DEFS_H__

/* Memories addresses and sizes*/

#define FLASH_MEM                               0x10000000
#define FLASH_MEM_SIZE                          0x100000        //1MiB

#define SFLASH_MEM                              0x00000000
#define SFLASH_MEM_SIZE                         0x10000         //32KiB

#define AUXFLASH_MEM                            0x00000000
#define AUXFLASH_MEM_SIZE                       0x10000         //32KiB

#define SRAM_MEM                                0x08000000
#define SRAM_MEM_SIZE                           0x48400         //288KiB

#endif  /* __MEM_DEFS_H__ */