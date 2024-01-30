#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x9c8,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9e6,
                .n_time = 103,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x9e6,
        .t_time = 21265,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0xa1e,
                .n_time = 5411,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0xa1e,
        .t_time = 26605,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9e6,
                .n_time = 89,
            },
            {
                .id = 3,
                .edge_addr = 0xa4a,
                .n_time = 5811346,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0xa4a,
        .t_time = 5837951,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9e6,
                .n_time = 0,
            },
            {
                .id = 4,
                .edge_addr = 0xa76,
                .n_time = 409,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0xa76,
        .t_time = 5838360,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x40001cc,
                .n_time = 95,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x40001cc,
        .t_time = 5838455,
        .edges = 0
    }
};
