#ifndef STACK_H
#define STACK_H

#include "string.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * @note
 * Define the three statements below to change the
 * type of the stack elements.
*/
typedef String * type;
#define TYPE_NULL_VALUE NULL

static inline void print_type(type value)
{
    print_string(value);
}

typedef struct Stack {
    int maxsize;
    int top;
    type *array;
} Stack;

Stack *create_stack(int maxsize);
void delete_stack(Stack *stack);

void push(Stack *stack, type value);
type pop(Stack *stack);

static inline type peek(Stack *stack)
{
    return stack->array[stack->top];
}

static inline bool is_empty_stack(Stack *stack)
{
    return stack->top < 0;
}

void print_stack(Stack *stack);

#endif
