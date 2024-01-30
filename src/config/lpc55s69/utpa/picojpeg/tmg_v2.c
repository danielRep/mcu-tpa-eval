#include "utpaconfig.h"
#include "cfgraph.h"

/* Definition of the Timed Milestone Graph */
mbb_t tmg[] =  // MBBs need to be declared in order
{
    {   /* Entry Point */
        .addr = 0x8dc,
        .t_time = 0,    /* always zero */
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 1,
                .edge_addr = 0x8f2,
                .n_time = 129,
            }
        }
    },
    {   /* MBB 1 */
        .addr = 0x8f2,
        .t_time = 129,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x902,
                .n_time = 78527,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x902,
        .t_time = 1205050,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x906,
                .n_time = 24672,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x906,
        .t_time = 1205151,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 2,
                .edge_addr = 0x902,
                .n_time = 54,
            },
            {
                .id = 4,
                .edge_addr = 0x910,
                .n_time = 65,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x910,
        .t_time = 1205216,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                //.edge_addr = 0x40001c4, //utpa_prof
                .edge_addr = 0x4000208, //utpa_mech
                .n_time = 103,
            }
        }

    },
    {   /* MBB 5 */
        //.addr = 0x40001c4, //utpa_prof
        .addr = 0x4000208, //utpa_mech
        .t_time = 1205319,
        .edges = 0,
    }
};
