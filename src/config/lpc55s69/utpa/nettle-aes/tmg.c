#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0xfa4,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0xfc6,
                .n_time = 129,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0xfc6,
        .t_time = 129,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x85c,
                .n_time = 2737,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x85c,
        .t_time = 2866,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x898,
                .n_time = 93,
            },
            {
                .id = 5,
                .edge_addr = 0xb04,
                .n_time = 0,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x898,
        .t_time = 92840,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x9d4,
                .n_time = 5582,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x9d4,
        .t_time = 98359,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x898,
                .n_time = 486,
            },
            {
                .id = 5,
                .edge_addr = 0xb04,
                .n_time = 448,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xb04,
        .t_time = 98807,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0xff8,
                .n_time = 2714,
            },
        }
    },
    {   /* MBB 6 */
        .addr = 0xff8,
        .t_time = 101521,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x1002,
                .n_time = 3933,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x1002,
        .t_time = 105454,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x101c,
                .n_time = 93300,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x101c,
        .t_time = 198754,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0xfc6,
                .n_time = 0,
            },
            {
                .id = 9,
                .edge_addr = 0x1020,
                .n_time = 51,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x1020,
        .t_time = 198805,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                //.edge_addr = 0x40001cc, //prof
                .edge_addr = 0x40001ec, //mech
                .n_time = 96,
            }
        }
    },
    {   /* MBB 10 */
        //.addr = 0x40001cc,  //prof
        .addr = 0x40001ec,  //mech
        .t_time = 198901,
        .edges = 0,
    }
};
