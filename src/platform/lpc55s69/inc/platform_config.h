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

#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

#include "fsl_clock.h"
#include "fsl_reset.h"

#ifdef CPU_LPC55S69JBD100_cm33_core0
#include "LPC55S69_cm33_core0.h"
#endif

#ifdef CPU_LPC55S69JBD100_cm33_core1
#include "LPC55S69_cm33_core1.h"
#endif
#ifndef __ASSEMBLER__

#define CPU_MHZ                                     150000000UL
#define UART0_CLK_FREQ                              12000000U
#define UART0_CLK_ATTACH                            kFRO12M_to_FLEXCOMM0
#define UART0_RST                                   kFC0_RST_SHIFT_RSTn

#define UART2_CLK_FREQ                              12000000U
#define UART2_CLK_ATTACH                            kFRO12M_to_FLEXCOMM2
#define UART2_RST                                   kFC1_RST_SHIFT_RSTn

int platform_init(void);

#endif  /* |__ASSEMBLER__ */
#endif /* __PLATFORM_CONFIG_H__ */
