#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

#include "linked_list.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @note
 * Queue.top is the head of the linked list.
 * New elements will be prepended and top will be changed.
*/
typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue *create_queue();
void delete_queue(Queue *queue);

static inline bool is_empty_queue(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int peek_front(Queue *queue);
int peek_rear(Queue *queue);

void print_queue(Queue *queue);

#endif
