#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue {
    int maxsize;
    int front, rear;
    int *array;
} Queue;

Queue *create_queue(int maxsize);
void delete_queue(Queue *queue);
void print_queue(const Queue *queue);

static inline bool is_empty_queue(Queue *queue)
{
    return queue->rear <= 0;
}

void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);

int peek_front(Queue *queue);
int peek_rear(Queue *queue);

#endif
