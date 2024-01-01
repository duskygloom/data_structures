#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include "linked_list.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @note
 * Stack.top is the head of the linked list.
 * New elements will be prepended and top will be changed.
*/
typedef struct Queue {
    Node *front;
} Queue;

Queue *create_stack();
void delete_stack(Queue *stack);

void push(Queue *stack, int value);
int pop(Queue *stack);
int peek(Queue *stack);

static inline bool is_empty_stack(Queue *stack)
{
    return stack->front == NULL;
}

void print_stack(Queue *stack);

#endif
