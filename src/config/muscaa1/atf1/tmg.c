#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x10200dc4,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x10200dca,
                .n_time = 1639,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x10200dca,
        .t_time = 1639,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x10200dd0,
                .n_time = 111509,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x10200dd0,
        .t_time = 113148,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x10200dd6,
                .n_time = 1419,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x10200dd6,
        .t_time = 114567,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x10200ddc,
                .n_time = 111509,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x10200ddc,
        .t_time = 226076,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x10200de2,
                .n_time = 1419,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x10200de2,
        .t_time = 227495,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x10200de8,
                .n_time = 111509,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x10200de8,
        .t_time = 339004,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x10200dea,
                .n_time = 1387,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x10200dea,
        .t_time = 2100431,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x10200df0,
                .n_time = 1451,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x10200df0,
        .t_time = 2101882,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0x10200df6,
                .n_time = 95541,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x10200df6,
        .t_time = 2197423,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0x10200dfc,
                .n_time = 1451,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0x10200dfc,
        .t_time = 2198874,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0x10200e02,
                .n_time = 95541,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0x10200e02,
        .t_time = 2294415,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x10200dea,
                .n_time = 1576,
            },
            {
                .id = 12,
                .edge_addr = 0x10200e06,
                .n_time = 1419,
            },
        }
    },
    {   /* MBB 12 */
        .addr = 0x10200e06,
        .t_time = 2295834,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 13,
                .edge_addr = 0x10200e0c,
                .n_time = 1451,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0x10200e0c,
        .t_time = 2297285,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x10200e12,
                .n_time = 95541,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0x10200e12,
        .t_time = 2392826,
        .edges = 0,
    },
};
