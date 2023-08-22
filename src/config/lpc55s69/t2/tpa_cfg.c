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
        .t_time = 1627,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 1627,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 14757,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 1,
                .time = 13130,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 17673,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 2,
                .time = 2916,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 20378,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 3,
                .time = 2705,
            },
        },
    },
    {   /* MBB 5 */
        .t_time = 22498,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 4,
                .time = 2120,
            },
        },
    },
    {   /* MBB 6 */
        .t_time = 48269,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 5,
                .time = 25771,
            },
        },
    },
    {   /* MBB 7 */
        .t_time = 77702,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 6,
                .time = 29433,
            },
        },
    },
    {   /* MBB 8 */
        .t_time = 162157,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 7,
                .time = 84455,
            },
        },
    },
    {   /* MBB 9 */
        .t_time = 2367303,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 8,
                .time = 2205146,
            },
        },
    },
    {   /* MBB 10 */
        .t_time = 2414800,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 9,
                .time = 47497,
            },
        },
    },
    {   /* MBB 11 */
        .t_time = 2416361,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 10,
                .time = 1561,
            },
        },
    },
    {   /* MBB 12 */
        .t_time = 2416546,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 11,
                .time = 185,
            },
        },
    },
    {   /* MBB 13 */
        .t_time = 2416696,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 12,
                .time = 150,
            },
        },
    },
};
