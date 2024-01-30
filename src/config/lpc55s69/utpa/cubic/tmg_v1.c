#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0xc38,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0xc6a,
                .n_time = 2519,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0xc6a,
        .t_time = 2519,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0xc86,
                .n_time = 45396,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0xc86,
        .t_time = 47915,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0xcc0,
                .n_time = 32738,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0xcc0,
        .t_time = 80653,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0xce8,
                .n_time = 34998,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0xce8,
        .t_time = 115651,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0xd28,
                .n_time = 34959,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xd28,
        .t_time = 150610,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xd50,
                .n_time = 46572,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xd50,
        .t_time = 197182,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0xdb6,
                .n_time = 320115,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0xdb6,
        .t_time = 517297,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x40001cc,
                .n_time = 371238,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x40001cc,      // utpaprof
        //.addr = 0x40001cc,    // utpamech
        .t_time = 888535,
        .edges = 0,
    },
};
