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
                .edge_addr = 0x1a9a,
                .n_time = 178,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x1a9a,
        .t_time = 178,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x1aa4,
                .n_time = 81,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x1aa4,
        .t_time = 3832486,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x1aae,
                .n_time = 55,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x1ab6,
        .t_time = 3832541,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x1ad0,
                .n_time = 1308439,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x1ad0,
        .t_time = 4048243,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x1aa4,
                .n_time = 68,
            },
            {
                .id = 5,
                .edge_addr = 0x1ad6,
                .n_time = 53,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x1ad6,
        .t_time = 4048296,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x1a9a,
                .n_time = 0,
            },
            {
                .id = 6,
                .edge_addr = 0x1ade,
                .n_time = 52,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x1ade,
        .t_time = 4048348,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                //.edge_addr = 0x40001cc, //utpa_prof
                .edge_addr = 0x4000208,    //utpa_mech
                .n_time = 96,
            }
        }
    },
    {   /* MBB 7 */
        //.addr = 0x40001cc,      //utpa_prof
        .addr = 0x4000208,    //utpa_mech
        .t_time = 4048444,
        .edges = 0,
    }
};
