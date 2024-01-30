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
                .edge_addr = 0x2910,
                .n_time = 69,
            }
        }
    },
    {   /* MBB 2 */
        .addr = 0x2910,
        .t_time = 198,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 3,
                .edge_addr = 0x2a6e,
                .n_time = 41720,
            }
        }
    },
    {   /* MBB 3 */
        .addr = 0x2a6e,
        .t_time = 41918,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 4,
                .edge_addr = 0x2b26,
                .n_time = 3502,
            }
        }
    },
    {   /* MBB 4 */
        .addr = 0x2b26,
        .t_time = 45420,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 5,
                .edge_addr = 0x2cea,
                .n_time = 32014,
            }
        }
    },
    {   /* MBB 5 */
        .addr = 0x2cea,
        .t_time = 77434,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x2db8,
                .n_time = 916,
            }
        }
    },
    {   /* MBB 6 */
        .addr = 0x2db8,
        .t_time = 1208069,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 7,
                .edge_addr = 0x902,
                .n_time = 575,
            }
        }
    },
    {   /* MBB 7 */
        .addr = 0x902,
        .t_time = 1208119,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 8,
                .edge_addr = 0x906,
                .n_time = 24672,
            }
        }
    },
    {   /* MBB 8 */
        .addr = 0x906,
        .t_time = 1208220,
        .edges = 2,
        .edge_mbbs =
        {
            {
                .id = 6,
                .edge_addr = 0x902,
                .n_time = 54,
            },
            {
                .id = 9,
                .edge_addr = 0x910,
                .n_time = 65,
            }
        }
    },
    {   /* MBB 9 */
        .addr = 0x910,
        .t_time = 1208285,
        .edges = 1,
        .edge_mbbs =
        {
            {
                .id = 10,
                //.edge_addr = 0x40001cc, //utpa_prof
                .edge_addr = 0x4000208, //utpa_mech
                .n_time = 103,
            }
        }
    },
    {   /* MBB 10 */
        //.addr = 0x40001cc, //utpa_prof
        .addr = 0x4000208, //utpa_mech
        .t_time = 1208388,
        .edges = 0,
    }
};
