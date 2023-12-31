#include "circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

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
    if (queue->front < queue->rear) {
        printf("%d", queue->array[queue->front]);
        for (int i = queue->front+1; i < queue->rear; ++i)
            printf(", %d", queue->array[i%queue->maxsize]);
    }
    printf("]\n");
}

bool enqueue(Queue *queue, int value)
{
    if (queue->rear - queue->front == queue->maxsize)
        return false;
    queue->array[(queue->rear)++] = value;
    return true;
}

int dequeue(Queue *queue)
{
    if (queue->front == queue->rear)
        return 0;
    return queue->array[(queue->front)++];
}
