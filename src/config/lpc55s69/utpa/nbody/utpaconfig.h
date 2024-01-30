#ifndef UTPACONFIG_H
#define UTPACONFIG_H

#include "utpa.h"

#define N_MBBS              8                       /* number of MBBs + entrypoint MBB*/
#define N_SUPP_EDGES        TOTAL_HW_BKPTS          /* number of supported edges per MBB (= hw breakpoints supported by the platform) */
#define LOG_MBB_HIT_SIZE    400                     /* number of MBBs hits allowed to be logged */

static uint32_t t_n_time = 5850683;                 /* nominal time of the current MBB */
static float alpha = 1.3;                           /* alpha is the accepted amount of the controlled degradation */
static float beta = 0.05;                           /* beta is an aggressiveness parameter [0, 1] controlling when interfering BMs are resumed. */

#endif  /* UTPACONFIG_H */
