#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0xcd8,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x8ec,
                .n_time = 3644,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x8ec,
        .t_time = 3644,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x960,
                .n_time = 41684,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x960,
        .t_time = 45328,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x980,
                .n_time = 4590,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x980,
        .t_time = 49918,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x9a2,
                .n_time = 2175,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x9a2,
        .t_time = 52093,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0xa2e,
                .n_time = 15549,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xa2e,
        .t_time = 67642,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xaa8,
                .n_time = 4958,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xaa8,
        .t_time = 72600,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0xaae,
                .n_time = 52,
            },
            {
                .id = 13,
                .edge_addr = 0xb2a,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0xaae,
        .t_time = 72652,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0xab4,
                .n_time = 52,
            },
            {
                .id = 13,
                .edge_addr = 0xb2a,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0xab4,
        .t_time = 72704,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0xb44,
                .n_time = 45334,
            },
            {
                .id = 13,
                .edge_addr = 0xb2a,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0xb44,
        .t_time = 118038,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0xb6c,
                .n_time = 6292,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0xb6c,
        .t_time = 124330,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0xc22,
                .n_time = 78494,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0xc22,
        .t_time = 202824,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 12,
                .edge_addr = 0xc82,
                .n_time = 106273,
            }
        }
    },
    {   /* MBB 12 */
        .addr = 0xc82,
        .t_time = 309097,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x40001cc,
                .n_time = 156,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0xb2a,
        .t_time = 0,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x40001cc,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0x40001cc,      // utpaprof
        //.addr = 0x40001cc,    // utpamech
        .t_time = 309253,
        .edges = 0,
    },
};
