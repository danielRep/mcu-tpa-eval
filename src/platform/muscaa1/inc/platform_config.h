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

#ifndef __ASSEMBLER__

#include "ARMCM33_DSP_FP_TZ.h"

#define CPU_MHZ                                     (50000000UL)

int platform_init(void);

#endif  /* |__ASSEMBLER__ */
#endif /* __PLATFORM_CONFIG_H__ */
