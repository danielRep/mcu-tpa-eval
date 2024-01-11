#ifndef __MEM_DEFS_H__
#define __MEM_DEFS_H__

/* Memories addresses and sizes*/
#define FLASH_MEM                           0x10200000
#define FLASH_MEM_SIZE                      0x800000

#define ISRAM0                              0x30000000
#define ISRAM1                              ISRAM0 + ISRAM_BANK_SIZE
#define ISRAM2                              ISRAM1 + ISRAM_BANK_SIZE
#define ISRAM3                              ISRAM2 + ISRAM_BANK_SIZE
#define ISRAM_BANK_SIZE                     0x8000

#define ESRAM0                              0x10000000
#define ESRAM1                              ESRAM0 + ESRAM_BANK_SIZE
#define ESRAM2                              ESRAM1 + ESRAM_BANK_SIZE
#define ESRAM3                              ESRAM2 + ESRAM_BANK_SIZE
#define ESRAM_BANK_SIZE                     0x80000

#endif  /* __MEM_DEFS_H__ */