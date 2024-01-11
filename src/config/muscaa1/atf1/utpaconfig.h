#ifndef UTPACONFIG_H
#define UTPACONFIG_H

#include "utpa.h"

#define T_N_TIME            0               /* total nominal time is calculated by the profiler */
#define N_MBBS              15              /* number of MBBs + entrypoint MBB*/
#define N_SUPP_EDGES        TOTAL_HW_BKPTS  /* number of supported edges per MBB (= hw breakpoints supported by the platform) */

static uint32_t t_n_time = T_N_TIME;

#endif  /* UTPACONFIG_H */
