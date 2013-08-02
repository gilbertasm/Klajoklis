#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define WHITE 1
#define GREY 2
#define BLACK 3



typedef struct Attribute_info_ {
    int color;
    int time;
    int estimate;
    int parent;
} Attribute_info;
    
typedef struct graph_ {
    
    /* Adjacency list representation of graph */
    Queue **q;
    
    /* Adjacency matrix representaion of graph */
    int **matrix;
    
    /* size of graph (vertex count) */
    int size;
    
    /* niceness of planets */
    int *planets;
    
    int global_time;
    
    Attribute_info **info;
    Queue *topological_order;
    
    
    
    
} Graph;

Graph *
initialise_graph (Graph *graph);
void print_queue_array (Graph *graph);
void read_file(Graph *graph, FILE *fp);
void  make_adjacent_list (Graph *graph);

#endif /* GRAPH_H */
