#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue*
initialise_queue (Queue *q) {
    q = malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit(-1);
    };
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int
insert_last(Queue *q, int vertex) {
    Elem *elem;
    
    elem = malloc(sizeof(Elem));
    if (elem == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit(-1);
    };
    
    elem->next = NULL;
    elem->vertex = vertex;
    
    if (q->head == NULL) {
        q->head = elem;
    }
    
    if (q->tail != NULL) {
        q->tail->next = elem;
    }
    
    q->tail  = elem;
    
    return 0;
}

int insert_first(Queue *q, int vertex) {
    Elem *elem;
    
    elem = malloc(sizeof(Elem));
    if (elem == NULL) {
        fprintf(stderr, "Malloc error. Quitting\n");
        exit (-1);
    };
    
    elem->next = q->head;
    elem->vertex = vertex;
    
    q->head = elem;
    
    
    if (q->tail == NULL) {
        q->tail = elem;
    }
    
    return 0;
    
}

void print_queue (Queue *q) {
    Elem *head = q->head;
    
    while (head != NULL) {
        printf("%d ", head->vertex);
        head = head->next;
    }
    printf("\n");
}
void free_queue(Queue *q) {
    Elem *next_elem;
    Elem *head = q->head;
    while (head != NULL) {
        next_elem = head->next;
        free(head);
        head = next_elem;
    }
    
    free(q);
}

