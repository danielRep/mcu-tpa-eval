#include "tpa.h"
#include "tpa_cfg.h"

tmg_t tmg_prof[N_MBBS] =
{
    {   /* Entry Point */
        .t_time = 0,
        .n_times = NULL,
        .edges = 1
    },
    {   /* MBB 1 */
        .t_time = 0,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 0,
            }
        },
        .edges = 1
    },
    {   /* MBB 2 */
        .t_time = 0,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 0,
            }
        },
        .edges = 1
    },
    {   /* MBB 3 */
        .t_time = 0,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 0,
            },
            {
                .src_mbb = 5,
                .time = 0,
            }
        },
        .edges = 2
    },
    {   /* MBB 4 */
        .t_time = 0,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 0,
            }
        },
        .edges = 1
    },
    {   /* MBB 5 */
        .t_time = 0,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 0,
            }
        },
        .edges = 1
    },
};
