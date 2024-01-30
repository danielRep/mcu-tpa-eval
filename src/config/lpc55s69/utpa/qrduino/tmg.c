#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x24cc,
        .t_time = 0,    /* always zero */
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x24d4,
                .n_time = 77,
            },
            {
                .id = 10,
                .edge_addr = 0x2526,
                .n_time = 0,
            },
        }
    },
    {   /* MBB 1 */
        .addr = 0x24d4,
        .t_time = 77,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x24ea,
                .n_time = 81,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x24ea,
        .t_time = 158,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x24fc,
                .n_time = 123,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x24fc,
        .t_time = 281,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x2504,
                .n_time = 642,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x2504,
        .t_time = 923,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x2512,
                .n_time = 252,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x2512,
        .t_time = 1175,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x2516,
                .n_time = 17120,
            },
        }
    },
    {   /* MBB 6 */
        .addr = 0x2516,
        .t_time = 18295,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x1128,
                .n_time = 3744,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x1128,
        .t_time = 22039,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x12b8,
                .n_time = 11740,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x12b8,
        .t_time = 33779,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                .edge_addr = 0x1682,
                .n_time = 882168,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x1682,
        .t_time = 915947,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                .edge_addr = 0x251a,
                .n_time = 15671,
            }
        }
    },
    {   /* MBB 10 */
        .addr = 0x251a,
        .t_time = 931618,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 11,
                .edge_addr = 0x251e,
                .n_time = 136,
            }
        }
    },
    {   /* MBB 11 */
        .addr = 0x251e,
        .t_time = 931754,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 12,
                .edge_addr = 0x2522,
                .n_time = 112,
            }
        }
    },
    {   /* MBB 12 */
        .addr = 0x2522,
        .t_time = 931866,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x24ea,
                .n_time = 0,
            },
            {
                .id = 13,
                .edge_addr = 0x2526,
                .n_time = 51,
            }
        }
    },
    {   /* MBB 13 */
        .addr = 0x2526,
        .t_time = 931917,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 14,
                //.edge_addr = 0x40001cc, //prof
                .edge_addr = 0x40001d0, //mech
                .n_time = 103,
            }
        }
    },
    {   /* MBB 14 */
        //.addr = 0x40001cc,  //prof
        .addr = 0x40001d0,  //mech
        .t_time = 932020,
        .edges = 0,
    }
};
