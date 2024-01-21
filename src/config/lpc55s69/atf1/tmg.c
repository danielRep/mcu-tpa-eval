#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x18ec,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x18f2,
                .n_time = 153,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x18f2,
        .t_time = 153,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x18f8,
                .n_time = 4148,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x18f8,
        .t_time = 4301,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x18fe,
                .n_time = 132,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x18fe,
        .t_time = 4433,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x1904,
                .n_time = 4147,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x1904,
        .t_time = 8580,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x190a,
                .n_time = 132,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x190a,
        .t_time = 8712,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x1910,
                .n_time = 4125,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x1910,
        .t_time = 12837,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x1912,
                .n_time = 131,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x1912,
        .t_time = 91061,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x1918,
                .n_time = 144,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x1918,
        .t_time = 91205,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0x191e,
                .n_time = 4124,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x191e,
        .t_time = 95329,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0x1924,
                .n_time = 141,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0x1924,
        .t_time = 95470,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0x192a,
                .n_time = 4122,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0x192a,
        .t_time = 99592,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x1912,
                .n_time = 146,
            },
            {
                .id = 12,
                .edge_addr = 0x192e,
                .n_time = 130,
            },
        }
    },
    {   /* MBB 12 */
        .addr = 0x192e,
        .t_time = 99722,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 13,
                .edge_addr = 0x1934,
                .n_time = 129,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0x1934,
        .t_time = 99851,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                .edge_addr = 0x193a,
                .n_time = 4110,
            }
        }
    },
    {   /* MBB 14 */
        .addr = 0x193a,
        .t_time = 103961,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 15,
                .edge_addr = 0x1b48,
                .n_time = 139,
            }
        }
    },
    {   /* MBB 15 */
        .addr = 0x1b48,
        .t_time = 104100,
        .edges = 0,
    },
};
