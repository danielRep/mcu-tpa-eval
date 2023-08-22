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
        .t_time = 120,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 120,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 358515,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 358395,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 456530,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 98015,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 814950,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 358420,
            },
        },
    },
    {   /* MBB 5 */
        .t_time = 1172182,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 4,
                .time = 357232,
            },
        },
    },
};
