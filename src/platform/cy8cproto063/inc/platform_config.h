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

#include "cyble_416045_02_device.h"

#ifndef __ASSEMBLER__

#define CM0_CPU_MHZ                                     100000000UL
#define CM4_CPU_MHZ                                     150000000UL
#define CPU_MHZ                                         CM4_CPU_MHZ
/* Definition for USARTx clock resources */

/* Definition for USARTx Pins */

/* Definition for USARTx's NVIC IRQ and IRQ Handlers */

int platform_init(void);

#endif  /* |__ASSEMBLER__ */
#endif /* __PLATFORM_CONFIG_H__ */
