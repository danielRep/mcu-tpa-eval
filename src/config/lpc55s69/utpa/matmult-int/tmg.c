#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x8ac,
        .t_time = 0,    /* always zero */
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x8b2,
                .n_time = 89,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x8b2,
        .t_time = 89,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x8b8,
                .n_time = 68,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x8b8,
        .t_time = 157,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x8c4,
                .n_time = 8109,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x8c4,
        .t_time = 8266,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x8d0,
                .n_time = 8104,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x8d0,
        .t_time = 16370,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x8dc,
                .n_time = 74674,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x8dc,
        .t_time = 91044,
        .type = NORMAL,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x8b8,
                .n_time = 0,
            },
            {
                .id = 6,
                .edge_addr = 0x8e0,
                .n_time = 63,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x8e0,
        .t_time = 91107,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                //.edge_addr = 0x40001e8, //prof
                .edge_addr = 0x40001fc, //mech
                .n_time = 94,
            }
        }
    },
    {   /* MBB 7 */
        //.addr = 0x40001e8,  //prof
        .addr = 0x40001fc,  //mech
        .t_time = 91201,
        .type = NORMAL,
        .edges = 0
    }
};
