#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Queue {
    int maxsize;
    int top;
    int *array;
} Queue;

Queue *create_stack(int maxsize);
void delete_stack(Queue *stack);

void push(Queue *stack, int value);
int pop(Queue *stack);
int peek(Queue *stack);

static inline bool is_empty_stack(Queue *stack)
{
    return stack->top < 0;
}

void print_stack(Queue *stack);

#endif
