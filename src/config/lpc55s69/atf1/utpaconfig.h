#ifndef UTPACONFIG_H
#define UTPACONFIG_H

#include "utpa.h"

#define T_N_TIME            104100          /* total nominal time is calculated by the profiler */
#define N_MBBS              16              /* number of MBBs + entrypoint MBB*/
#define N_SUPP_EDGES        TOTAL_HW_BKPTS  /* number of supported edges per MBB (= hw breakpoints supported by the platform) */
#define LOG_MBB_HIT_SIZE    200             /* number of MBBs hits allowed to be logged */
#define IRQ_IPI             31              /* IRQ number of the IPI */

static uint32_t t_n_time = T_N_TIME;

#endif  /* UTPACONFIG_H */
