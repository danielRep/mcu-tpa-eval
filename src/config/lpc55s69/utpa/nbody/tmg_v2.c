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
                .edge_addr = 0x9d8,
                .n_time = 78,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x9d8,
        .t_time = 78,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0xa1e,
                .n_time = 5061,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0xa1e,
        .t_time = 5139,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0xa2e,
                .n_time = 21214,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0xa2e,
        .t_time = 26353,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0xa4a,
                .n_time = 5811312,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0xa4a,
        .t_time = 5837665,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x40001cc,
                .n_time = 454,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x40001cc,
        .t_time = 5838119,
        .edges = 0,
    },
};
