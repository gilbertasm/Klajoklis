#include "queue.h"
#include "matrix.h"
#include "graph.h"
#include "algorithms.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    FILE *fp;
    Graph *graph;
    char *filename = "duom.txt";
    
    
    fp = fopen(filename, "r");
 
    if (fp == NULL) {
        fprintf(stderr,"Failed to open file filename\n");
        return -1;
    }
    
    graph = initialise_graph(graph);
    read_file (graph, fp);
    make_adjacent_list(graph);
    
    find_shortest_path(graph, 0);
    print_path (graph, 0, graph->size - 1);
      
    return 0;
    
}
