#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x10200d40,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x10200d46,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x10200d46,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x10200d4c,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x10200d4c,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x10200d52,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x10200d52,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x10200d58,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x10200d58,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x10200d5e,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x10200d5e,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x10200d64,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x10200d64,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x10200d66,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x10200d66,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x10200d6c,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x10200d6c,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0x10200d72,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x10200d72,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0x10200d78,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0x10200d78,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0x10200d7e,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0x10200d7e,
        .t_time = 0,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x10200d66,
                .n_time = 0,
            },
            {
                .id = 12,
                .edge_addr = 0x10200d82,
                .n_time = 0,
            },
        }
    },
    {   /* MBB 12 */
        .addr = 0x10200d82,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 13,
                .edge_addr = 0x10200d88,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0x10200d88,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x10200d8e,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0x10200d8e,
        .t_time = 0,
        .edges = 0,
    },
};
