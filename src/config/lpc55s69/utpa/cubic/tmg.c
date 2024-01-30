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
                .edge_addr = 0xd10,
                .n_time = 34959,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xd10,
        .t_time = 518043,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xd50,
                .n_time = 46586,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xd50,
        .t_time = 842560,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0xd78,
                .n_time = 46816,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0xd78,
        .t_time = 888898,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0xd84,
                .n_time = 307,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0xd84,
        .t_time = 889205,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xd50,
                .n_time = 46853,
            },
            {
                .id = 9,
                .edge_addr = 0xda0,
                .n_time = 308,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0xda0,
        .t_time = 889513,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xd50,
                .n_time = 44474,
            },
            {
                .id = 10,
                .edge_addr = 0xdb6,
                .n_time = 290,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0xdb6,
        .t_time = 889803,
        .edges = 3,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0xc6a,
                .n_time = 0,
            },
            {
                .id = 5,
                .edge_addr = 0xd10,
                .n_time = 101,
            },
            {
                .id = 11,
                .edge_addr = 0xdca,
                .n_time = 67,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0xdca,
        .t_time = 889870,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 12,
                .edge_addr = 0x4000208,
                .n_time = 123,
            }
        }
    },
    {   /* MBB 12 */
        //.addr = 0x40001cc,      // utpaprof
        .addr = 0x4000208,    // utpamech
        .t_time = 889993,
        .edges = 0,
    },
};
