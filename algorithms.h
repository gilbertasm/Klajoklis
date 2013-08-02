#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "graph.h"

void dfs_visit (Graph *graph, int u);
int dfs (Graph *graph);
void initialise_single_source (Graph *graph, int s);
void relax (Graph *graph, int u, int v );
void print_path (Graph *g, int s, int v);
void print_path (Graph *g, int s, int v);
void find_shortest_path(Graph *graph, int s);

#endif /* ALGORITHMS_H */