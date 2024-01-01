#include "circular_queue_linked.h"

#include <stdlib.h>

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void delete_queue(Queue *queue)
{
    if (queue->front) delete_list(&(queue->front), &(queue->rear));
    free(queue);
}

void enqueue(Queue *queue, int value)
{
    append(&(queue->front), &(queue->rear), value);
}

int dequeue(Queue *queue)
{
    if (is_empty_queue(queue)) printf("Underflow.\n");
    return pop_head(&(queue->front), &(queue->rear));
}

int peek_front(Queue *queue)
{
    if (is_empty_queue(queue)) {
        printf("Empty queue.\n");
        return -1;
    }
    return queue->front->value;
}

int peek_rear(Queue *queue)
{
    if (is_empty_queue(queue)) {
        printf("Empty queue.\n");
        return -1;
    }
    return queue->rear->value;
}

void print_queue(Queue *queue)
{
    print_list(queue->front);
}
