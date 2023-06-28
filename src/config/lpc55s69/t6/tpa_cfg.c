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
        .t_time = 221,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 221,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 997,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 776,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 1757,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 760,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 14752,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 12995,
            },
        },
    },
    {   /* MBB 5 */
        .t_time = 16368,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 4,
                .time = 1616,
            },
        },
    },
    {   /* MBB 6 */
        .t_time = 17763,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 5,
                .time = 1395,
            },
        },
    },
    {   /* MBB 7 */
        .t_time = 19203,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 6,
                .time = 1440,
            },
        },
    },
    {   /* MBB 8 */
        .t_time = 20478,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 7,
                .time = 1275,
            },
        },
    },
    {   /* MBB 9 */
        .t_time = 22548,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 8,
                .time = 2070,
            },
        },
    },
    {   /* MBB 10 */
        .t_time = 47903,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 9,
                .time = 165,
            },
        },
    },
    {   /* MBB 11 */
        .t_time = 49264,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 10,
                .time = 1361,
            },
        },
    },
    {   /* MBB 12 */
        .t_time = 79157,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 11,
                .time = 29893,
            },
        },
    },
    {   /* MBB 13 */
        .t_time = 149687,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 12,
                .time = 70530,
            },
        },
    },
    {   /* MBB 14 */
        .t_time = 152322,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 13,
                .time = 2635,
            },
        },
    },
    {   /* MBB 15 */
        .t_time = 2352418,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 14,
                .time = 2200096,
            },
        },
    },
    {   /* MBB 16 */
        .t_time = 2403546,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 15,
                .time = 51128,
            },
        },
    },
    {   /* MBB 17 */
        .t_time = 2403816,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 16,
                .time = 270,
            },
        },
    },
};
