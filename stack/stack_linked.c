#include "stack_linked.h"

#include <stdlib.h>

Queue *create_stack()
{
    Queue *stack = malloc(sizeof(Queue));
    stack->front = NULL;
    return stack;
}

void delete_stack(Queue *stack)
{
    if (stack->front) delete_list(&(stack->front));
    free(stack);
}

void push(Queue *stack, int value)
{
    prepend(&(stack->front), value);
}

int pop(Queue *stack)
{
    if (is_empty_stack(stack)) printf("Underflow.\n");
    return pop_head(&(stack->front));
}

int peek(Queue *stack)
{
    if (is_empty_stack(stack)) printf("Empty stack.\n");
    return stack->front->value;
}

void print_stack(Queue *stack)
{
    print_list(stack->front);
}
