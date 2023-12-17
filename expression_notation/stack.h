#ifndef STACK_H
#define STACK_H

#include "string.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct Stack {
    int maxsize;
    int top;
    String **array;
} Stack;

Stack *create_stack(int maxsize);
void delete_stack(Stack *stack);

void push(Stack *stack, String *value);
String *pop(Stack *stack);

static inline String *peek(const Stack *stack)
{
    if (stack->top <= 0) {
        printf("Stack underflow.\n");
        return NULL;
    }
    return stack->array[stack->top-1];
}

static inline bool is_empty_stack(const Stack *stack)
{
    return stack->top <= 0;
}

void print_stack(const Stack *stack);

#endif
