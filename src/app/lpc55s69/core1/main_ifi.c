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

#include "content_eval.h"
#include "platform_config.h"
#include "platform_base_addrs.h"
#include "fsl_mailbox.h"
#include "ipi.h"

extern void fill_cache();

void Interrupt31_Handler(void)  // IPI interrupt handler
{
    uint32_t msg = MAILBOX_GetValue(MAILBOX, kMAILBOX_CM33_Core1);
    MAILBOX_ClearValueBits(MAILBOX, kMAILBOX_CM33_Core1, 0xffffffff);

    if(msg == CORUNNER_PAUSE)
    {
        #ifdef LOGGING
        printf("TPA_MECH: Co-runner paused.\r\n");
        #endif
        __WFI();
    }
    else    //CORUNNER_RESUME
    {
        #ifdef LOGGING
        printf("TPA_MECH: Co-runner resumed.\r\n");
        #endif
    }
}

int main(void)
{
    /* Init platform specific hardware */
    platform_init();
    printf("Hello from core1!\r\n");

    while(1)
    {
#ifdef C1_STATS

#endif

    fill_cache();
#ifdef C1_STATS

#endif
    #ifdef LOGGING
    printf("TPA_MECH: Co-runner running.\r\n");
    #endif
    }
    return 0;
}
