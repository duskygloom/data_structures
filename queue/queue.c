#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *create_queue(int maxsize)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->maxsize = maxsize;
    queue->array = calloc(maxsize, sizeof(int));
    queue->front = queue->rear = 0;
    return queue;
}

void delete_queue(Queue *queue)
{
    if (queue) {
        if (queue->array) free(queue->array);
        free(queue);
    }
}

void print_queue(const Queue *queue)
{
    putchar('[');
    if (queue->rear > 0)
        printf("%d", queue->array[queue->front]);
    for (int i = 1; i < queue->rear; ++i)
        printf(", %d", queue->array[i]);
    printf("]\n");
}

void enqueue(Queue *queue, int value)
{
    if (queue->rear >= queue->maxsize) {
        printf("Overflow.\n");
        return;
    }
    queue->array[(queue->rear)++] = value;
}

int dequeue(Queue *queue)
{
    if (is_empty_queue(queue)) {
        printf("Underflow.\n");
        return -1;
    }
    int value = queue->array[queue->front];
    for (int i = queue->front+1; i < queue->rear; ++i)
        queue->array[i-1] = queue->array[i];
    --(queue->rear);
    return value;
}

int peek_front(Queue *queue)
{
    if (is_empty_queue(queue)) {
        printf("Empty queue.\n");
        return -1;
    }
    return queue->array[queue->front];
}

int peek_rear(Queue *queue)
{
    if (is_empty_queue(queue)) {
        printf("Empty queue.\n");
        return -1;
    }
    return queue->array[queue->rear-1];
}
