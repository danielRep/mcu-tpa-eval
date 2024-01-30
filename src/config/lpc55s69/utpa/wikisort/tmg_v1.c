#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x1a6c,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x1aa4,
                .n_time = 216,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x1aa4,
        .t_time = 3832043,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x1ad0,
                .n_time = 1308444,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x1ad0,
        .t_time = 4047750,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x1aa4,
                .n_time = 68,
            },
            {
                .id = 3,
                .edge_addr = 0x1ade,
                .n_time = 55,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x1ade,
        .t_time = 4047805,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x40001fc,
                .n_time = 96,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x40001fc,
        .t_time = 4047901,
        .edges = 0,
    }
};
