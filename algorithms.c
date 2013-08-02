#include "algorithms.h"
#include <limits.h>


/* Visists node during DFS search, and later 
 * saves it into topological_order queue */

void dfs_visit (Graph *graph, int u) {
    Elem *adj_list, *head;
    int v;
    
    graph->global_time++;
    graph->info[u]->color = GREY;
    
    adj_list = graph->q[u]->head;
    head = adj_list;
    
    while (head != NULL) {
        v = head->vertex;
        
        if (graph->info[v]->color ==  WHITE) {
            dfs_visit(graph, v);
        }
        
        head = head->next;
    }
    
    
  
    
    graph->info[u]->color = BLACK;
    graph->global_time++;
    graph->info[u]->time = graph->global_time;
    
    insert_first(graph->topological_order, u);
    
    
    
}


void initialise_single_source (Graph *graph, int s) {
    int i;
     
    for (i = 0; i < graph->size; i++) {
        graph->info[i]->parent = -1;
        graph->info[i]->estimate = INT_MAX;
         
        
         
        /* If planet is unfriendly, penalize it 
        
        if (graph->planets[i] == 0) {
            graph->planets[i] = INT_MAX;
        } */
    } 
     
    graph->info[s]->estimate = 0;
}
 
void relax (Graph *graph, int u, int v ) {
    int estimate_u, estimate_v, estimate;
     
    estimate_u = graph->info[u]->estimate;
    estimate_v = graph->info[v]->estimate;
     
    estimate = estimate_u + graph->matrix[u][v] + graph->planets[v];

     
    if (estimate_v > estimate) {
        graph->info[v]->estimate = estimate;
        graph->info[v]->parent = u;
    }
}

void print_path (Graph *g, int s, int v) {
    
    if (v == s) {
        //printf("%d ", s);
    }  
    else {
        print_path(g, s, g->info[v]->parent);
    }
    
    
    if (v == 0) {
        printf("Pradėjom kelionė iš planetos %d \n", v);
        //printf("%d->", v);
    } else {
        if (g->planets[v] == 0) {
            printf ("Praplaukiame planetą %d (joje neišsilaipindami!), atkarpos gerumas %d, ",
                    v, abs(g->matrix[g->info[v]->parent][v]));
            printf("planeta nedraugiška, bendras naudingumas %d\n", abs(g->info[v]->estimate));
            
        }  else {
               printf ("Išsilaipinome planetoje %d, atkarpos gerumas %d, planetos gerumas %d, bendras naudingumas %d\n",
                       v, abs(g->matrix[g->info[v]->parent][v]), abs(g->planets[v]), abs(g->info[v]->estimate));
        }
       
    }
}
        
/* Implements DFS algorithm which, in effect,
 * finds the topological order of graph and saves it into 
 * topological_order queue */
         
int dfs (Graph *graph) {
    int i, size;
    Attribute_info **info;
    info = graph->info;
    
    size = graph->size;
    for (i = 0; i < size; i++) {
        info[i]->color = WHITE;
    }
    
    graph->global_time = 0;
    for (i = 0; i < size; i++) {
        if (info[i]->color == WHITE) 
            dfs_visit(graph, 0);
    }
    
    return 0;
}

void find_shortest_path(Graph *graph, int s) {
    Elem *head1;
    Elem *head2;
    int vertex_u, vertex_v;
    
    /*DFS will find topological order, which will bee needed later */
    graph->topological_order = initialise_queue(graph->topological_order);
    dfs(graph);
    
    initialise_single_source(graph, s);
    
    for (head1 = graph->topological_order->head; head1 != NULL; head1 = head1->next) {
        vertex_u = head1->vertex;
        for (head2 = graph->q[vertex_u]->head; head2 != NULL; head2 = head2->next) {
            vertex_v = head2->vertex;
            relax(graph, vertex_u, vertex_v);
        }
    }
   
}