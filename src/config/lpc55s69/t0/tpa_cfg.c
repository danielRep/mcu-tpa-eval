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
        .t_time = 155,
        .edges = 3,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 155,
            },
            {
                .src_mbb = 3,
                .time = 155,
            },
            {
                .src_mbb = 2,
                .time = 155,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 590,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 435,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 10010,
        .edges = 2,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 435,
            },
            {
                .src_mbb = 4,
                .time = 415,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 10485,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 475,
            },
        },
    },
    {   /* MBB 5 */
        .t_time = 9595,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 4,
                .time = 485,
            },
        },
    },
};
