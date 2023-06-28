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
        .t_time = 175,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 175,
            },
        },
    },
    {   /* MBB 2 */
        .t_time = 615,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 3 */
        .t_time = 1055,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 4 */
        .t_time = 1495,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 5 */
        .t_time = 1935,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 6 */
        .t_time = 2375,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 7 */
        .t_time = 2815,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 8 */
        .t_time = 3255,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 9 */
        .t_time = 3695,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 10 */
        .t_time = 4135,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 11 */
        .t_time = 4575,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 12 */
        .t_time = 5015,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 13 */
        .t_time = 5455,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 14 */
        .t_time = 5895,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 15 */
        .t_time = 6335,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 16 */
        .t_time = 6775,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 17 */
        .t_time = 7215,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 18 */
        .t_time = 7655,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 19 */
        .t_time = 8095,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 20 */
        .t_time = 8535,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 21 */
        .t_time = 8975,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 22 */
        .t_time = 9415,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 23 */
        .t_time = 9855,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 24 */
        .t_time = 10295,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 25 */
        .t_time = 10735,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 26 */
        .t_time = 11175,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 27 */
        .t_time = 11615,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 28 */
        .t_time = 12055,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 29 */
        .t_time = 12495,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 30 */
        .t_time = 12935,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 31 */
        .t_time = 13375,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 32 */
        .t_time = 13815,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 33 */
        .t_time = 14255,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 34 */
        .t_time = 14695,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 35 */
        .t_time = 15135,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 36 */
        .t_time = 15575,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 37 */
        .t_time = 16015,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 38 */
        .t_time = 16455,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 39 */
        .t_time = 16895,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 40 */
        .t_time = 17335,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 41 */
        .t_time = 17775,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 42 */
        .t_time = 18215,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 43 */
        .t_time = 18655,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 44 */
        .t_time = 19095,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 45 */
        .t_time = 19535,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 46 */
        .t_time = 19975,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 47 */
        .t_time = 20415,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 48 */
        .t_time = 20855,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 49 */
        .t_time = 21295,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 50 */
        .t_time = 21735,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 51 */
        .t_time = 22175,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 52 */
        .t_time = 22615,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 53 */
        .t_time = 23055,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 54 */
        .t_time = 23495,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 55 */
        .t_time = 23935,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 56 */
        .t_time = 24375,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 57 */
        .t_time = 24815,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 58 */
        .t_time = 25255,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 59 */
        .t_time = 25695,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 60 */
        .t_time = 26135,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 61 */
        .t_time = 26575,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 62 */
        .t_time = 27015,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 63 */
        .t_time = 27455,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 64 */
        .t_time = 27895,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 65 */
        .t_time = 28335,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 66 */
        .t_time = 28775,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 67 */
        .t_time = 29215,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 68 */
        .t_time = 29655,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 69 */
        .t_time = 30095,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 70 */
        .t_time = 30535,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 71 */
        .t_time = 30975,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 72 */
        .t_time = 31415,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 73 */
        .t_time = 31855,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 74 */
        .t_time = 32295,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 75 */
        .t_time = 32735,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 76 */
        .t_time = 33175,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 77 */
        .t_time = 33615,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 78 */
        .t_time = 34055,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 79 */
        .t_time = 34495,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 80 */
        .t_time = 34935,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 81 */
        .t_time = 35375,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 82 */
        .t_time = 35815,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 83 */
        .t_time = 36255,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 84 */
        .t_time = 36695,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 85 */
        .t_time = 37135,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 86 */
        .t_time = 37575,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 87 */
        .t_time = 38015,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 88 */
        .t_time = 38455,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 89 */
        .t_time = 38895,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 90 */
        .t_time = 39335,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 91 */
        .t_time = 39775,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 92 */
        .t_time = 40215,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 93 */
        .t_time = 40655,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 94 */
        .t_time = 41095,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 95 */
        .t_time = 41535,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 96 */
        .t_time = 41975,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 97 */
        .t_time = 42415,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 98 */
        .t_time = 42855,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 99 */
        .t_time = 43295,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
    {   /* MBB 100 */
        .t_time = 43735,
        .edges = 1,
        .n_times = (n_time_t[])
        {
            {
                .src_mbb = 0,
                .time = 440,
            },
        },
    },
};
