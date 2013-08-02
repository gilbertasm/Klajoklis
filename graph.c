#include "graph.h"
#include "matrix.h"

Graph *
initialise_graph (Graph *graph) {
    
    graph = malloc (sizeof(Graph));
    graph->q = NULL;
    graph->matrix = NULL;
    graph->size = 0;
    graph->planets = NULL;
    graph->info = NULL;
    graph->topological_order = NULL;
    graph->info = NULL;
    return graph;
}

void print_queue_array (Graph *graph) {
    int i;
    int size = graph->size;
    
    for (i = 0; i < size; i++) {
        printf("Vertex %d: ", i);
        print_queue(graph->q[i]);
    }
}

/* Initialize adjacency matrix and other things
 * from data file 
 * Make costs negative, so that shortest path algorithm
 * would find logest path
 * Because graph must be DAG, this works correctly */

void
read_file(Graph *graph, FILE *fp) {
    int size, i, **matrix, *planets;
    int edge_number, vt1, vt2, cost;
    Attribute_info **info = NULL;
    
    fscanf(fp, "%d", &size);
    planets = malloc (size * sizeof(int));
    
    if (planets == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit (-1);
    }
    
    matrix = initialise_matrix(graph->matrix, size);
   
    
    for (i = 0; i < size; i++) {
        fscanf(fp, "%d", planets + i);
        planets[i] = planets[i] * (-1);
    }
    
    fscanf(fp, "%d", &edge_number);
    
    while( fscanf(fp, "%d %d %d" , &vt1, &vt2, &cost) == 3 ) {
        matrix[vt1][vt2] = cost * (-1);
        //matrix[vt1][vt2] += planetos[vt2];
    }
    
    info = malloc (size * sizeof (Attribute_info *));
    if (info == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit (-1);
    }
    
    for (i = 0; i < size; i++) {
        info[i] = calloc (1, sizeof (Attribute_info));
        
        
        if (info[i] == NULL) {
            fprintf(stderr, "Calloc error. Quitting!");
            exit (-1);
        }
        
    }
        
        
    graph->planets = planets;
    graph->size = size;
    graph->matrix = matrix;
    graph->info = info;
    
    
}


/* Make adjacency list from adjacency matrix
 * Needed for DFS and topological sort */
 
void
make_adjacent_list (Graph *graph) {
    
    int i, j, value;
    int size = graph->size;
    graph->q = malloc( sizeof (Queue *) * size);
    
    if (graph->q == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit (-1);
    };
    
    for (i = 0; i < size; i++) {
        graph->q[i] = malloc (sizeof(Graph));
        graph->q[i]->head = NULL;
        graph->q[i]->tail = NULL;
        
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            value = graph->matrix[i][j];
            if (value < 0) {
                insert_last (graph->q[i], j);
            }
        }
    } 
    
   
}