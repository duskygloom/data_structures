#ifndef STACK_H
#define STACK_H

#include "string.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct Queue {
    int maxsize;
    int top;
    String **array;
} Queue;

Queue *create_stack(int maxsize);
void delete_stack(Queue *stack);

void push(Queue *stack, String *value);
String *pop(Queue *stack);

static inline String *peek(const Queue *stack)
{
    if (stack->top <= 0) {
        printf("Stack underflow.\n");
        return NULL;
    }
    return stack->array[stack->top-1];
}

static inline bool is_empty_stack(const Queue *stack)
{
    return stack->top <= 0;
}

void print_stack(const Queue *stack);

#endif
