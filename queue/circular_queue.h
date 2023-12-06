#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <stdbool.h>

typedef struct Queue {
    int maxsize;
    int front, rear;
    int *array;
} Queue;

Queue *create_queue(int maxsize);
void delete_queue(Queue *queue);
void print_queue(const Queue *queue);

bool enqueue(Queue *queue, int value);
int dequeue(Queue *queue);

#endif
