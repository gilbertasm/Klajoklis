#ifndef QUEUE_H
#define QUEUE_H
 


typedef struct elem_ {
    struct elem_ *next;
    int vertex;
} Elem;

typedef struct queue_ {
    Elem *head;
    Elem *tail;
} Queue;

Queue* initialise_queue (Queue *q);
int insert_last(Queue *q, int vertex);
int insert_first(Queue *q, int vertex);
void print_queue (Queue *q);
void free_queue(Queue *q);

#endif /* QUEUE_H */