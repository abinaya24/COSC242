/**
 * File: graph-app.c
 * @author Josh King.
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/**
 * Function: main
 * Purpose: Creates a new graph with a size read from stdin. Then creates
 * edges inside the graph between two vertices read from stdin. Finally
 * performs a depth-first search on the graph and prints its contents and
 * search information.
 *
 * @return The exit status of the program.
 */
int main(void){

    graph g;
    int size, a, b;

    scanf("%d", &size); 
    g = graph_new(size);

    while(scanf("%d %d", &a, &b) != -1){
        add_edge_bi(g, a, b);
    }

    g = graph_bfs(g, 1);

    print_graph(g);

    
    graph_free(g);

    return EXIT_SUCCESS;
}
