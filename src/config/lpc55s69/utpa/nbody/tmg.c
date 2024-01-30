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
                .edge_addr = 0xa2e,
                .n_time = 77,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0xa2e,
        .t_time = 5790636,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0xa42,
                .n_time = 58169,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0xa42,
        .t_time = 5848793,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0xa2e,
                .n_time = 67,
            },
            {
                .id = 5,
                .edge_addr = 0xa4a,
                .n_time = 53,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xa4a,
        .t_time = 5848846,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9e6,
                .n_time = 0,
            },
            {
                .id = 6,
                .edge_addr = 0xa76,
                .n_time = 409,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xa76,
        .t_time = 5849255,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                //.edge_addr = 0x40001cc,     //utpaprof
                .edge_addr = 0x4000208,     //utpamech
                .n_time = 95,
            }
        }
    },
    {   /* MBB 7 */
        //.addr = 0x40001cc,      //utpaprof
        .addr = 0x4000208,      //utpamech
        .t_time = 5849350,
        .edges = 0
    }
};
