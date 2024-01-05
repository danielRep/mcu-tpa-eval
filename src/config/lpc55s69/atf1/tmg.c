#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x18d0,
        .t_time = 0,    /* always zero */
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x18d6,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x18d6,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x18dc,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x18dc,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x18e2,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x18e2,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x18e8,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x18e8,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x18ee,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x18ee,
        .t_time = 0,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x18f4,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x18f4,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x18f6,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x18f6,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x18fc,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x18fc,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0x1902,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x1902,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0x1908,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0x1908,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0x190e,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0x190e,
        .t_time = 0,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x18f6,
                .n_time = 0,
            },
            {
                .id = 12,
                .edge_addr = 0x1912,
                .n_time = 0,
            },
        }
    },
    {   /* MBB 12 */
        .addr = 0x1912,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 13,
                .edge_addr = 0x1918,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0x1918,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x191e,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0x191e,
        .t_time = 0,
        .edges = 0,
    },
};
