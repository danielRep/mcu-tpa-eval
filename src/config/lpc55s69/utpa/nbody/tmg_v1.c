#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x9c8,
        .t_time = 0,    /* always zero */
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9d8,
                .n_time = 80,
            },
            {
                .id = 17,
                .edge_addr = 0xa76,
                .n_time = 2516,
            },
        }
    },
    {   /* MBB 1 */
        .addr = 0x9d8,
        .t_time = 80,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x9e2,
                .n_time = 68,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x9e2,
        .t_time = 148,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x9e6,
                .n_time = 51,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x9e6,
        .t_time = 20111,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x9f0,
                .n_time = 78,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x9f0,
        .t_time = 24165,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x9fc,
                .n_time = 214,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x9fc,
        .t_time = 24379,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xa0a,
                .n_time = 1408,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xa0a,
        .t_time = 25785,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0xa16,
                .n_time = 320,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0xa16,
        .t_time = 26084,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x9f0,
                .n_time = 68,
            },
            {
                .id = 8,
                .edge_addr = 0xa1e,
                .n_time = 54,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0xa1e,
        .t_time = 26138,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x9e6,
                .n_time = 89,
            },
            {
                .id = 9,
                .edge_addr = 0xa28,
                .n_time = 75,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0xa28,
        .t_time = 26213,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0xa2e,
                .n_time = 53,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0xa2e,
        .t_time = 26266,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0xa36,
                .n_time = 57905,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0xa36,
        .t_time = 84171,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 12,
                .edge_addr = 0xa42,
                .n_time = 157,
            }
        }
    },
    {   /* MBB 12 */
        .addr = 0xa42,
        .t_time = 84328,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 13,
                .edge_addr = 0xa4a,
                .n_time = 5753367,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0xa4a,
        .t_time = 5837695,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x9e2,
                .n_time = 0,
            },
            {
                .id = 14,
                .edge_addr = 0xa56,
                .n_time = 62,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0xa56,
        .t_time = 5837757,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 15,
                .edge_addr = 0xa60,
                .n_time = 189,
            }
        }
    },
    {   /* MBB 15 */
        .addr = 0xa60,
        .t_time = 5837946,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 16,
                .edge_addr = 0xa70,
                .n_time = 251,
            }
        }
    },
    {   /* MBB 16 */
        .addr = 0xa70,
        .t_time = 5838197,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 17,
                .edge_addr = 0xa76,
                .n_time = 52,
            }
        }
    },
    {   /* MBB 17 */
        .addr = 0xa76,
        .t_time = 5838249,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 18,
                .edge_addr = 0x4000270,
                .n_time = 108,
            }
        }
    },
    {   /* MBB 18 */
        .addr = 0x4000270,
        .t_time = 5838353,
        .edges = 0,
    },
};
