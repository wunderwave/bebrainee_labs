#include "graphs/graph.h"
# include <stdio.h>


/* --------------------------------------------------------------------------
 *   FORWARD DECLARATIONS 
 * --------------------------------------------------------------------------*/

/* Builds randmom tree for graph
 * ============================= */
static __build_random_tree ( RCGraph * p_graph );

/* Initializes new graph on griven pointer
 * ======================================= */
RCG_Create_Status_T _initRCGraph ( struct __newgraph_params__ * args );





/* --------------------------------------------------------------------------
 *   DEFINITIONS
 * --------------------------------------------------------------------------*/
// static __get_random_unique_category ( )
// static int __build_random_graph_tree (RCGraph * p_graph)
// {
//     int roots_count = p_graph->roots_count;
//     int c = 0;

//     while ( c < roots_count )
//     {
//         __build_graph_tree_segment ( p_graph, rand_vertice_count )
//     }
//     int coutnrer = 0;
//     int vertice_rand_rel_count;

//     int * sarray = malloc ( sizeof (desired_count) );
//     while ( counter < desired_count )
//     {
        
//     }
// }


RCG_Create_Status_T _initRCGraph( struct __newgraph_params__ * args )
{
    char * gname = args->name;
    int vcount = args->vertices_count;

    // Set default name if not provided
    if ( ! gname )
        gname = "RCG - Relevant Category (Page) Graph";

    // If negative number of vertices provided
    // this comment is just for dumbs or very smart people like Einstein
    if (vcount <= 0)
        vcount = 1;

    RCGraph * gp = *(args->graph_ptr) = & ( RCGraph ) {
        .name = gname,
        .vertices_count = vcount
    };
    
    char vname[512];
    int c = -1;

    gp->root = malloc ( sizeof(RCG_Vertice)  );
    --vcount;
    
    while (c++ < vcount)
    {
        sprintf(vname, "v%d", c);
        (gp->vertices)[c] = &(RCG_Vertice){ .name = vname };
    }

    if (args->create_random_vertices)
        gp->__build_random_tree(gp);


    return 1;
}
