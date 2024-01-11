#include "tpa.h"
#include "tpa_cfg.h"

tmg_t tmg_prof[N_MBBS] =
{
    {   /* MBB 0 */
        .t_time = 0,
        .edges = 0,
        .n_times = NULL,
    },
    {   /* MBB 1 */
        .t_time = 45921,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 45921,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 76835,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 30914,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 109674,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 32839,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 841789,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 380356,
            },
        },
    },
};
