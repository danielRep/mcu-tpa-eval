#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x9a0,
        .t_time = 188962,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x9c0,
                .n_time = 1658,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x9c0,
        .t_time = 190620,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 0,
                .edge_addr = 0x9a0,
                .n_time = 251,
            },
            {
                .id = 2,
                .edge_addr = 0xa08,
                .n_time = 23378,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0xa08,
        .t_time = 213998,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0xa1c,
                .n_time = 315,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0xa1c,
        .t_time = 214313,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0xa7a,
                .n_time = 68300,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0xa7a,
        .t_time = 471967,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0xa9a,
                .n_time = 1666,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0xa9a,
        .t_time = 473633,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0xa7a,
                .n_time = 250,
            },
            {
                .id = 6,
                .edge_addr = 0xb00,
                .n_time = 23702,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0xb00,
        .t_time = 497335,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0xb46,
                .n_time = 237938,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0xb46,
        .t_time = 735273,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 0,
                .edge_addr = 0x9a0,
                .n_time = 0,
            },
            {
                .id = 8,
                .edge_addr = 0xb4e,
                .n_time = 54,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0xb4e,
        .t_time = 735327,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 9,
                //.edge_addr = 0x40001cc,   //prof
                .edge_addr = 0x40001fc,   //mech
                .n_time = 107,
            }
        }
    },
    {   /* MBB 9 */
        //.addr = 0x40001cc,  //prof
        .addr = 0x40001fc,  //mech
        .t_time = 735434,
        .edges = 0,
    }
};
