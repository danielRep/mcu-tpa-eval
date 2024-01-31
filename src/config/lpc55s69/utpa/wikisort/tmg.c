#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x1a6c,
        .t_time = 0,    /* always zero */
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x1a9a,
                .n_time = 179,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x1a9a,
        .t_time = 179,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x1aa4,
                .n_time = 84,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x1aa4,
        .t_time = 3832993,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x1aae,
                .n_time = 58,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x1aae,
        .t_time = 3833051,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x1ab6,
                .n_time = 2507,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x1ab6,
        .t_time = 3833208,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x1ad0,
                .n_time = 449232,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x1ad0,
        .t_time = 4051601,
        .type = LOOP_EXIT,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x1aa4,
                .n_time = 71,
            },
            {
                .id = 6,
                .edge_addr = 0x1ad6,
                .n_time = 56,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x1ad6,
        .t_time = 4051657,
        .type = NORMAL,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x1a9a,
                .n_time = 0,
            },
            {
                .id = 7,
                .edge_addr = 0x1ade,
                .n_time = 55,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x1ade,
        .t_time = 4051712,
        .type = NORMAL,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                //.edge_addr = 0x40001e4, //utpa_prof
                .edge_addr = 0x40001fc,    //utpa_mech
                .n_time = 99,
            }
        }
    },
    {   /* MBB 8 */
        //.addr = 0x40001e4,      //utpa_prof
        .addr = 0x40001fc,    //utpa_mech
        .t_time = 4051811,
        .type = NORMAL,
        .edges = 0,
    }
};
