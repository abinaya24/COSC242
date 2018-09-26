/**
 * File: graph.c
 * @author: Josh King.
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

/**
 * Enum: state_t
 * Purpose: Store data about wheter a vertex has been visted or not.
 */
typedef enum state_e {UNVISITED,VISITED_SELF,VISITED_DESCENDANTS} state_t;

/**
 * Struct: vertex
 * Purpose: Store information about a vertex in a graph.
 */
struct vertex{
    int predecessor;
    int distance;
    state_t state;
    int finish;
};

/**
 * Struct: graphrec
 * Purpose: Store information about an overall graph structure.
 */    
struct graphrec{
    int size;
    struct vertex *vertices;
    int **edges;
};

/**
 * Function: graph_new
 * Purpose: Creates a new graph with a given number of verticies and no edges.
 *
 * @param Number of verticies in the created graph.
 * @return The graph created.
 */
graph graph_new(int num_vertices){

    int i,j;   
    graph result = emalloc(sizeof *result);

    result->size = num_vertices;
    
    result->vertices = emalloc(num_vertices * sizeof result->vertices[0]);
    
    result->edges = emalloc(sizeof result->edges[0] * num_vertices);


    for (i = 0; i < num_vertices; i++){
        result->edges[i] = emalloc(sizeof result->edges[0][0] * num_vertices);

        for (j = 0; j < num_vertices; j++){
            result->edges[i][j] = 0;
        }
    }

    return result;
    
}

/**
 * Function: graph_free
 * Purpose: Delete a graph and free the memory allocated to it.
 *
 * @param The graph to be deleted.
 */
void graph_free(graph g){

    int i;

    for (i = 0; i < g->size; i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g->vertices);
    free(g);

    return;

}

/**
 * Function: add_edge_bi
 * Purpose: Add a bi-directional edge between two vertices.
 *
 * @param Graph the edge will be added to. 
 * @param First vertex.
 * @param Second vertex.
 */
void add_edge_bi(graph g, int u, int v){
    g->edges[u][v] = 1;
    g->edges[v][u] = 1;
}

/**
 * Function: add_edge_uni
 * Purpose: Add a uni-directional edge from vertex u to vertex v.
 *
 * @param Graph the edge will be added to.
 * @param The origin vertex.
 * @param The destination vertex.
 */
void add_edge_uni(graph g, int u, int v){
    g->edges[u][v] = 1;
}

/**
 * Function: print_graph
 * Purpose: Print the contents of a graph, the adjancency and information
 * about its vertices.
 *
 * @param Graph to be printed.
 */
void print_graph(graph g){

    int i, j;

    printf("adjacency list:\n");
    for (i = 0; i < g->size; i++){
        printf("%d |", i);
        for (j = 0; j < g->size; j++){
            if (g->edges[i][j] == 1){
                printf(" %d,", j);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    printf("%s\t%s  %s", "vertex", "distance", "pred\n");
    for (i = 0; i < g->size; i++){
        printf("%5d%8d%8d\n", i, g->vertices[i].distance, g->vertices[i].predecessor);
    }
    
}

/**
 * Function: graph_bfs
 * Purpose: Perform a breadth-frist search on a graph.
 *
 * @param Graph for the search to be performed on.
 * @return The graph with extra information gathered by the search.
 */
graph graph_bfs(graph g, int source){

    int i, u, v;
    queue q = queue_new();

    for (i = 0; i < g->size; i++){
        g->vertices[i].state = UNVISITED;
        g->vertices[i].distance = -1;
        g->vertices[i].predecessor = -1;
    }
    g->vertices[source].state = VISITED_SELF;
    g->vertices[source].distance = 0;
    enqueue(q, source);

    while (queue_size(q) > 0){
        u = dequeue(q);

        for (v = 0; v < g->size; v++){
            if (g->vertices[v].state == UNVISITED && g->edges[u][v] == 1){
                g->vertices[v].state = VISITED_SELF;
                g->vertices[v].distance = 1 + g->vertices[u].distance;     
                g->vertices[v].predecessor = u;
                enqueue(q, v); 
            }
        }

        g->vertices[u].state = VISITED_DESCENDANTS;
    }

    free(q);

    return g;
 
}
