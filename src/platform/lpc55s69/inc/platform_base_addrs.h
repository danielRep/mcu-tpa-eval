/*
 * Copyright (c) 2017-2019 Arm Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.01 Device\_Template_Vendor\Vendor\Device\Include\Device.h
 */

#ifndef __PLATFORM_BASE_ADDRS_H__
#define __PLATFORM_BASE_ADDRS_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

/** Peripheral SYSCON base address */
#define SYSCON_BASE                                 (0x40000000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                      ((SYSCON_type *)SYSCON_BASE)
#define SYSCON_CPUCFG_CPU1ENABLE_MASK               (0x4U)
#define SYSCON_CPUCFG_CPU1ENABLE_SHIFT              (2U)
#define SYSCON_CPUCTRL_CPU1CLKEN_MASK               (0x8U)
#define SYSCON_CPUCTRL_CPU1CLKEN_SHIFT              (3U)
#define SYSCON_CPUCTRL_CPU1RSTEN_MASK               (0x20U)
#define SYSCON_CPUCTRL_CPU1RSTEN_SHIFT              (5U)

#define MPU_TYPE                                    (0xE000ED90UL)
#define MPU_TYPE_DREGION                            (0xFF00U)
#ifndef __ASSEMBLER__

#include "content_eval.h"

/*!
    * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
    * @{
    */

/** SYSCON - Register Layout Typedef */
typedef struct
{
    __RW uint32_t MEMORYREMAP; /**< Memory Remap control register, offset: 0x0 */
    uint8_t RESERVED_0[12];
    __RW uint32_t AHBMATPRIO; /**< AHB Matrix priority control register Priority values are 3 = highest, 0 = lowest, offset: 0x10 */
    uint8_t RESERVED_1[36];
    __RW uint32_t CPU0STCKCAL;  /**< System tick calibration for secure part of CPU0, offset: 0x38 */
    __RW uint32_t CPU0NSTCKCAL; /**< System tick calibration for non-secure part of CPU0, offset: 0x3C */
    __RW uint32_t CPU1STCKCAL;  /**< System tick calibration for CPU1, offset: 0x40 */
    uint8_t RESERVED_2[4];
    __RW uint32_t NMISRC; /**< NMI Source Select, offset: 0x48 */
    uint8_t RESERVED_3[180];
    union
    { /* offset: 0x100 */
        struct
        {                              /* offset: 0x100 */
            __RW uint32_t PRESETCTRL0; /**< Peripheral reset control 0, offset: 0x100 */
            __RW uint32_t PRESETCTRL1; /**< Peripheral reset control 1, offset: 0x104 */
            __RW uint32_t PRESETCTRL2; /**< Peripheral reset control 2, offset: 0x108 */
        } PRESETCTRL;
        __RW uint32_t PRESETCTRLX[3]; /**< Peripheral reset control register, array offset: 0x100, array step: 0x4 */
    };
    uint8_t RESERVED_4[20];
    __RW uint32_t PRESETCTRLSET[3]; /**< Peripheral reset control set register, array offset: 0x120, array step: 0x4 */
    uint8_t RESERVED_5[20];
    __RW uint32_t PRESETCTRLCLR[3]; /**< Peripheral reset control clear register, array offset: 0x140, array step: 0x4 */
    uint8_t RESERVED_6[20];
    __WO uint32_t SWR_RESET; /**< generate a software_reset, offset: 0x160 */
    uint8_t RESERVED_7[156];
    union
    { /* offset: 0x200 */
        struct
        {                              /* offset: 0x200 */
            __RW uint32_t AHBCLKCTRL0; /**< AHB Clock control 0, offset: 0x200 */
            __RW uint32_t AHBCLKCTRL1; /**< AHB Clock control 1, offset: 0x204 */
            __RW uint32_t AHBCLKCTRL2; /**< AHB Clock control 2, offset: 0x208 */
        } AHBCLKCTRL;
        __RW uint32_t AHBCLKCTRLX[3]; /**< Peripheral reset control register, array offset: 0x200, array step: 0x4 */
    };
    uint8_t RESERVED_8[20];
    __RW uint32_t AHBCLKCTRLSET[3]; /**< Peripheral reset control register, array offset: 0x220, array step: 0x4 */
    uint8_t RESERVED_9[20];
    __RW uint32_t AHBCLKCTRLCLR[3]; /**< Peripheral reset control register, array offset: 0x240, array step: 0x4 */
    uint8_t RESERVED_10[20];
    union
    { /* offset: 0x260 */
        struct
        {                                 /* offset: 0x260 */
            __RW uint32_t SYSTICKCLKSEL0; /**< System Tick Timer for CPU0 source select, offset: 0x260 */
            __RW uint32_t SYSTICKCLKSEL1; /**< System Tick Timer for CPU1 source select, offset: 0x264 */
        } SYSTICKCLKSEL;
        __RW uint32_t SYSTICKCLKSELX[2]; /**< Peripheral reset control register, array offset: 0x260, array step: 0x4 */
    };
    __RW uint32_t TRACECLKSEL; /**< Trace clock source select, offset: 0x268 */
    union
    { /* offset: 0x26C */
        struct
        {                                /* offset: 0x26C */
            __RW uint32_t CTIMERCLKSEL0; /**< CTimer 0 clock source select, offset: 0x26C */
            __RW uint32_t CTIMERCLKSEL1; /**< CTimer 1 clock source select, offset: 0x270 */
            __RW uint32_t CTIMERCLKSEL2; /**< CTimer 2 clock source select, offset: 0x274 */
            __RW uint32_t CTIMERCLKSEL3; /**< CTimer 3 clock source select, offset: 0x278 */
            __RW uint32_t CTIMERCLKSEL4; /**< CTimer 4 clock source select, offset: 0x27C */
        } CTIMERCLKSEL;
        __RW uint32_t CTIMERCLKSELX[5]; /**< Peripheral reset control register, array offset: 0x26C, array step: 0x4 */
    };
    __RW uint32_t MAINCLKSELA; /**< Main clock A source select, offset: 0x280 */
    __RW uint32_t MAINCLKSELB; /**< Main clock source select, offset: 0x284 */
    __RW uint32_t CLKOUTSEL;   /**< CLKOUT clock source select, offset: 0x288 */
    uint8_t RESERVED_11[4];
    __RW uint32_t PLL0CLKSEL; /**< PLL0 clock source select, offset: 0x290 */
    __RW uint32_t PLL1CLKSEL; /**< PLL1 clock source select, offset: 0x294 */
    uint8_t RESERVED_12[12];
    __RW uint32_t ADCCLKSEL;  /**< ADC clock source select, offset: 0x2A4 */
    __RW uint32_t USB0CLKSEL; /**< FS USB clock source select, offset: 0x2A8 */
    uint8_t RESERVED_13[4];
    union
    { /* offset: 0x2B0 */
        struct
        {                            /* offset: 0x2B0 */
            __RW uint32_t FCCLKSEL0; /**< Flexcomm Interface 0 clock source select for Fractional Rate Divider, offset: 0x2B0 */
            __RW uint32_t FCCLKSEL1; /**< Flexcomm Interface 1 clock source select for Fractional Rate Divider, offset: 0x2B4 */
            __RW uint32_t FCCLKSEL2; /**< Flexcomm Interface 2 clock source select for Fractional Rate Divider, offset: 0x2B8 */
            __RW uint32_t FCCLKSEL3; /**< Flexcomm Interface 3 clock source select for Fractional Rate Divider, offset: 0x2BC */
            __RW uint32_t FCCLKSEL4; /**< Flexcomm Interface 4 clock source select for Fractional Rate Divider, offset: 0x2C0 */
            __RW uint32_t FCCLKSEL5; /**< Flexcomm Interface 5 clock source select for Fractional Rate Divider, offset: 0x2C4 */
            __RW uint32_t FCCLKSEL6; /**< Flexcomm Interface 6 clock source select for Fractional Rate Divider, offset: 0x2C8 */
            __RW uint32_t FCCLKSEL7; /**< Flexcomm Interface 7 clock source select for Fractional Rate Divider, offset: 0x2CC */
        } FCCLKSEL;
        __RW uint32_t FCCLKSELX[8]; /**< Peripheral reset control register, array offset: 0x2B0, array step: 0x4 */
    };
    __RW uint32_t HSLSPICLKSEL; /**< HS LSPI clock source select, offset: 0x2D0 */
    uint8_t RESERVED_14[12];
    __RW uint32_t MCLKCLKSEL; /**< MCLK clock source select, offset: 0x2E0 */
    uint8_t RESERVED_15[12];
    __RW uint32_t SCTCLKSEL; /**< SCTimer/PWM clock source select, offset: 0x2F0 */
    uint8_t RESERVED_16[4];
    __RW uint32_t SDIOCLKSEL; /**< SDIO clock source select, offset: 0x2F8 */
    uint8_t RESERVED_17[4];
    __RW uint32_t SYSTICKCLKDIV0; /**< System Tick Timer divider for CPU0, offset: 0x300 */
    __RW uint32_t SYSTICKCLKDIV1; /**< System Tick Timer divider for CPU1, offset: 0x304 */
    __RW uint32_t TRACECLKDIV;    /**< TRACE clock divider, offset: 0x308 */
    uint8_t RESERVED_18[20];
    union
    { /* offset: 0x320 */
        struct
        {                               /* offset: 0x320 */
            __RW uint32_t FLEXFRG0CTRL; /**< Fractional rate divider for flexcomm 0, offset: 0x320 */
            __RW uint32_t FLEXFRG1CTRL; /**< Fractional rate divider for flexcomm 1, offset: 0x324 */
            __RW uint32_t FLEXFRG2CTRL; /**< Fractional rate divider for flexcomm 2, offset: 0x328 */
            __RW uint32_t FLEXFRG3CTRL; /**< Fractional rate divider for flexcomm 3, offset: 0x32C */
            __RW uint32_t FLEXFRG4CTRL; /**< Fractional rate divider for flexcomm 4, offset: 0x330 */
            __RW uint32_t FLEXFRG5CTRL; /**< Fractional rate divider for flexcomm 5, offset: 0x334 */
            __RW uint32_t FLEXFRG6CTRL; /**< Fractional rate divider for flexcomm 6, offset: 0x338 */
            __RW uint32_t FLEXFRG7CTRL; /**< Fractional rate divider for flexcomm 7, offset: 0x33C */
        } FLEXFRGCTRL;
        __RW uint32_t FLEXFRGXCTRL[8]; /**< Peripheral reset control register, array offset: 0x320, array step: 0x4 */
    };
    uint8_t RESERVED_19[64];
    __RW uint32_t AHBCLKDIV; /**< System clock divider, offset: 0x380 */
    __RW uint32_t CLKOUTDIV; /**< CLKOUT clock divider, offset: 0x384 */
    __RW uint32_t FROHFDIV;  /**< FRO_HF (96MHz) clock divider, offset: 0x388 */
    __RW uint32_t WDTCLKDIV; /**< WDT clock divider, offset: 0x38C */
    uint8_t RESERVED_20[4];
    __RW uint32_t ADCCLKDIV;  /**< ADC clock divider, offset: 0x394 */
    __RW uint32_t USB0CLKDIV; /**< USB0 Clock divider, offset: 0x398 */
    uint8_t RESERVED_21[16];
    __RW uint32_t MCLKDIV; /**< I2S MCLK clock divider, offset: 0x3AC */
    uint8_t RESERVED_22[4];
    __RW uint32_t SCTCLKDIV; /**< SCT/PWM clock divider, offset: 0x3B4 */
    uint8_t RESERVED_23[4];
    __RW uint32_t SDIOCLKDIV; /**< SDIO clock divider, offset: 0x3BC */
    uint8_t RESERVED_24[4];
    __RW uint32_t PLL0CLKDIV; /**< PLL0 clock divider, offset: 0x3C4 */
    uint8_t RESERVED_25[52];
    __RW uint32_t CLOCKGENUPDATELOCKOUT; /**< Control clock configuration registers access (like xxxDIV, xxxSEL), offset: 0x3FC */
    __RW uint32_t FMCCR;                 /**< FMC configuration register, offset: 0x400 */
    uint8_t RESERVED_26[8];
    __RW uint32_t USB0NEEDCLKCTRL; /**< USB0 need clock control, offset: 0x40C */
    __RO uint32_t USB0NEEDCLKSTAT; /**< USB0 need clock status, offset: 0x410 */
    uint8_t RESERVED_27[8];
    __WO uint32_t FMCFLUSH;        /**< FMCflush control, offset: 0x41C */
    __RW uint32_t MCLKIO;          /**< MCLK control, offset: 0x420 */
    __RW uint32_t USB1NEEDCLKCTRL; /**< USB1 need clock control, offset: 0x424 */
    __RO uint32_t USB1NEEDCLKSTAT; /**< USB1 need clock status, offset: 0x428 */
    uint8_t RESERVED_28[52];
    __RW uint32_t SDIOCLKCTRL; /**< SDIO CCLKIN phase and delay control, offset: 0x460 */
    uint8_t RESERVED_29[252];
    __RW uint32_t PLL1CTRL; /**< PLL1 550m control, offset: 0x560 */
    __RO uint32_t PLL1STAT; /**< PLL1 550m status, offset: 0x564 */
    __RW uint32_t PLL1NDEC; /**< PLL1 550m N divider, offset: 0x568 */
    __RW uint32_t PLL1MDEC; /**< PLL1 550m M divider, offset: 0x56C */
    __RW uint32_t PLL1PDEC; /**< PLL1 550m P divider, offset: 0x570 */
    uint8_t RESERVED_30[12];
    __RW uint32_t PLL0CTRL;  /**< PLL0 550m control, offset: 0x580 */
    __RO uint32_t PLL0STAT;  /**< PLL0 550m status, offset: 0x584 */
    __RW uint32_t PLL0NDEC;  /**< PLL0 550m N divider, offset: 0x588 */
    __RW uint32_t PLL0PDEC;  /**< PLL0 550m P divider, offset: 0x58C */
    __RW uint32_t PLL0SSCG0; /**< PLL0 Spread Spectrum Wrapper control register 0, offset: 0x590 */
    __RW uint32_t PLL0SSCG1; /**< PLL0 Spread Spectrum Wrapper control register 1, offset: 0x594 */
    uint8_t RESERVED_31[364];
    __RW uint32_t FUNCRETENTIONCTRL; /**< Functional retention control register, offset: 0x704 */
    uint8_t RESERVED_32[248];
    __RW uint32_t CPUCTRL; /**< CPU Control for multiple processors, offset: 0x800 */
    __RW uint32_t CPBOOT;  /**< Coprocessor Boot Address, offset: 0x804 */
    uint8_t RESERVED_33[4];
    __RO uint32_t CPSTAT; /**< CPU Status, offset: 0x80C */
    uint8_t RESERVED_34[520];
    __RW uint32_t CLOCK_CTRL; /**< Various system clock controls : Flash clock (48 MHz) control, clocks to Frequency Measures, offset: 0xA18 */
    uint8_t RESERVED_35[244];
    __RW uint32_t COMP_INT_CTRL;   /**< Comparator Interrupt control, offset: 0xB10 */
    __RO uint32_t COMP_INT_STATUS; /**< Comparator Interrupt status, offset: 0xB14 */
    uint8_t RESERVED_36[748];
    __RW uint32_t AUTOCLKGATEOVERRIDE; /**< Control automatic clock gating, offset: 0xE04 */
    __RW uint32_t GPIOPSYNC;           /**< Enable bypass of the first stage of synchonization inside GPIO_INT module, offset: 0xE08 */
    uint8_t RESERVED_37[404];
    __RW uint32_t DEBUG_LOCK_EN;     /**< Control write access to security registers., offset: 0xFA0 */
    __RW uint32_t DEBUG_FEATURES;    /**< Cortex M33 (CPU0) and micro Cortex M33 (CPU1) debug features control., offset: 0xFA4 */
    __RW uint32_t DEBUG_FEATURES_DP; /**< Cortex M33 (CPU0) and micro Cortex M33 (CPU1) debug features control DUPLICATE register., offset: 0xFA8 */
    uint8_t RESERVED_38[16];
    __WO uint32_t KEY_BLOCK;         /**< block quiddikey/PUF all index., offset: 0xFBC */
    __RW uint32_t DEBUG_AUTH_BEACON; /**< Debug authentication BEACON register, offset: 0xFC0 */
    uint8_t RESERVED_39[16];
    __RW uint32_t CPUCFG; /**< CPUs configuration register, offset: 0xFD4 */
    uint8_t RESERVED_40[32];
    __RO uint32_t DEVICE_ID0; /**< Device ID, offset: 0xFF8 */
    __RO uint32_t DIEID;      /**< Chip revision ID and Number, offset: 0xFFC */
} SYSCON_type;

#endif /* |__ASSEMBLER__ */
#ifdef __cplusplus
}
#endif

#endif /* __PLATFORM_BASE_ADDRS_H__ */
