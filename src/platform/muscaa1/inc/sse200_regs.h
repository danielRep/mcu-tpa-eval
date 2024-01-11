/*
 * Authors:
 *      Daniel Oliveira <daniel.oliveira@tango-project.org>
 *      Sandro Pinto <sandro.pinto@tango-project.org>
 *
 * contention-eval is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 */

#ifndef __SSE200_REGS_H__
#define __SSE200_REGS_H__

#include "platform_base_addrs.h"

/* ==== Private CPU Regions (PCPU) ========================================== */
#define PCPU_BASE_S                             (MUSCA_CPU_ELEMENT_S_BASE)
#define PCPU_BASE_NS                            (MUSCA_CPU_ELEMENT_NS_BASE)

/* ==== CPU Identity (CPUIDT) =============================================== */
#define CPUIDT_BASE_S                           (PCPU_BASE_S + 0xF000UL)
#define CPUIDT_S                                ((CPUIDT_type*)CPUIDT_BASE_S)
#define CPUIDT_BASE_NS                          (PCPU_BASE_NS + 0xF000UL)
#define CPUIDT_NS                               ((CPUIDT_type*)CPUIDT_BASE_NS)

/* ==== Instruction Cache Configuration Registers (ICCR_S) ================== */
#define ICCR_BASE_S                             (PCPU_BASE_S)
#define ICCR                                    ((ICCR_type*)ICCR_BASE_S)

/* ==== System Control Region (SCReg) ======================================= */
#define SCR_BASE_S                              (MUSCA_SYSTEM_CTRL_S_BASE)

/* ==== System Control Register block (SCR_S) =============================== */
#define SCR                                     ((SCR_type*)SCR_BASE_S)

#ifndef __ASSEMBLER__

#include "content_eval.h"

/* struct type to access the CPU Identity regions */
typedef struct
{
    __RO uint32_t CPU_IDENTITY;
    __RO uint32_t RESERVED0[1011U];
} CPUIDT_type;

/* struct type to access System Control Register block */
typedef struct
{
    __RO uint32_t SECDBGSTAT;
    __WO uint32_t SECDBGSET;
    __WO uint32_t SECDBGCLR;
    __RW uint32_t SCSECCTRL;
    __RW uint32_t FCLK_DIV;
    __RW uint32_t SYSCLK_DIV;
    __RW uint32_t CLOCKFORCE;
    __RO uint32_t RESERVED0[57];
    __RW uint32_t RESETSYNDROME;
    __RW uint32_t RESETMASK;
    __WO uint32_t SWRESET;
    __RW uint32_t GRETREG;
    __RW uint32_t INITSVTOR0;
    __RW uint32_t INITSVTOR1;
    __RW uint32_t CPUWAIT;
    __RW uint32_t NMI_ENABLE;
    __RW uint32_t WICCTRL;
    __RW uint32_t EWCTRL;
    __RO uint32_t RESERVED1[54];
    __RW uint32_t PDCM_PD_SYS_SENSE;
    __RO uint32_t RESERVED2[2];
    __RW uint32_t PDCM_PD_SRAM0_SENSE;
    __RW uint32_t PDCM_PD_SRAM1_SENSE;
    __RW uint32_t PDCM_PD_SRAM2_SENSE;
    __RW uint32_t PDCM_PD_SRAM3_SENSE;
} SCR_type;

/* ==== Serial Configuration Control (SCC) ================================== */
#define SCC_BASE_S                                  (MUSCA_SCC_S_BASE)
#define SCC                                         ((SCC_type*)SCC_BASE_S)

/* struct type to access NSPCB */
typedef struct
{
    volatile uint32_t RESET_CTRL;
    volatile uint32_t CLK_CTRL;
    volatile uint32_t PWR_CTRL;
    volatile uint32_t PLL_CTRL;
    volatile uint32_t DBG_CTRL;
    volatile uint32_t SRAM_CTRL;
    volatile uint32_t INTR_CTRL;
    volatile uint32_t RESERVED1;
    volatile uint32_t CPU0_VTOR_SRAM;
    volatile uint32_t CPU0_VTOR_FLASH;
    volatile uint32_t CPU1_VTOR_SRAM;
    volatile uint32_t CPU1_VTOR_FLASH;
    volatile uint32_t IOMUX_MAIN_INSEL;
    volatile uint32_t IOMUX_MAIN_OUTSEL;
    volatile uint32_t IOMUX_MAIN_OENSEL;
    volatile uint32_t IOMUX_MAIN_DEFAULT_IN;
    volatile uint32_t IOMUX_ALTF1_INSEL;
    volatile uint32_t IOMUX_ALTF1_OUTSEL;
    volatile uint32_t IOMUX_ALTF1_OENSEL;
    volatile uint32_t IOMUX_ALTF1_DEFAULT_IN;
    volatile uint32_t IOMUX_ALTF2_INSEL;
    volatile uint32_t IOMUX_ALTF2_OUTSEL;
    volatile uint32_t IOMUX_ALTF2_OENSEL;
    volatile uint32_t IOMUX_ALTF2_DEFAULT_IN;
    volatile uint32_t PVT_CTRL;
    volatile uint32_t SPARE0;
    volatile uint32_t IOPAD_DS0;
    volatile uint32_t IOPAD_DS1;
    volatile uint32_t IOPAD_PE;
    volatile uint32_t IOPAD_PS;
    volatile uint32_t IOPAD_SR;
    volatile uint32_t IOPAD_IS;
    volatile uint32_t SRAM_RW_MARGINE;
    volatile uint32_t STATIC_CONF_SIG0;
    volatile uint32_t STATIC_CONF_SIG1;
    volatile uint32_t REQ_SET;
    volatile uint32_t REQ_CLEAR;
    volatile uint32_t IOMUX_ALTF3_INSEL;
    volatile uint32_t IOMUX_ALTF3_OUTSEL;
    volatile uint32_t IOMUX_ALTF3_OENSEL;
    volatile uint32_t IOMUX_ALTF3_DEFAULT_IN;
    volatile uint32_t PCSM_CTRL_OVERRIDE;
    volatile uint32_t PD_CPU0_ISO_OVERRIDE;
    volatile uint32_t PD_CPU1_ISO_OVERRIDE;
    volatile uint32_t SYS_SRAM_RW_ASSIST0;
    volatile uint32_t SYS_SRAM_RW_ASSIST1;
    volatile uint32_t SYS_SRAM_RW_ASSIST2;
    volatile uint32_t SYS_SRAM_RW_ASSIST3;
    volatile uint32_t SYS_SRAM_RW_ASSIST4;
    volatile uint32_t SYS_SRAM_RW_ASSIST5;
    volatile uint32_t RESERVED2[3];
    volatile uint32_t CRYPTO_SRAM_RW_ASSIST0;
    volatile uint32_t CRYPTO_SRAM_RW_ASSIST1;
    volatile uint32_t CRYPTO_SRAM_RW_ASSIST2;
    volatile uint32_t REQ_EDGE_SEL;
    volatile uint32_t REQ_ENABLE;
    volatile uint32_t RESERVED3[28];
    volatile uint32_t CHIP_ID;
    volatile uint32_t CLOCK_STATUS;
    volatile uint32_t IO_IN_STATUS;
} SCC_type;

/* struct type to access Instruction Cache Configuration Registers block */
typedef struct{
    __RO uint32_t ICHWPARAMS;            /* Read Only - Hardware Parameter Register*/
    __RW uint32_t ICCTRL;                /* Read and Write - Instruction Cache Control Register */
    __RO uint32_t RESERVED0[62U];
    __RO uint32_t ICIRQSTAT;             /* Read Only - Interrupt Request Status Register */
    __WO uint32_t ICIRQSCLR;             /* Write Only - Interrupt Status Clear register */
    __RW uint32_t ICIRQEN;               /* Read and Write - Interrupt Enable Register */
    __RO uint32_t ICDBGFILLERR;          /* Read Only - Debug Fill Error Register */
    __RO uint32_t RESERVED1[124U];
    __RO uint32_t ICSH;                  /* Read Only - Instruction Cache Hit Statistics Hit Register */
    __RO uint32_t ICSM;                  /* Read Only - Instruction Cache Statistic Miss Count Register */
    __RO uint32_t ICSUC;                 /* Read Only - Instruction Cache Statistics Uncached Count Register */
    __RO uint32_t RESERVED3[331U];
    __RO uint32_t PIDR4;
    __RO uint32_t PIDR5;
    __RO uint32_t PIDR6;
    __RO uint32_t PIDR7;
    __RO uint32_t PIDR0;
    __RO uint32_t PIDR1;
    __RO uint32_t PIDR2;
    __RO uint32_t PIDR3;
    __RO uint32_t CIDR0;
    __RO uint32_t CIDR1;
    __RO uint32_t CIDR2;
    __RO uint32_t CIDR3;
}ICCR_Type;

#endif  /* |__ASSEMBLER__ */
#endif /* __SSE200_REGS_H__ */
