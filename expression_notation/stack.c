#include "stack.h"

#include <stdlib.h>

Queue *create_stack(int maxsize)
{
    Queue *stack = malloc(sizeof(Queue));
    if (stack) {
        stack->maxsize  = maxsize;
        stack->top      = 0;
        stack->array    = calloc(maxsize, sizeof(String *));
    }
    return stack;
}

/**
 * @note
 * All the functions assume that the stack is not NULL.
*/

void delete_stack(Queue *stack)
{
    if (stack->array) free(stack->array);
    free(stack);
}

void push(Queue *stack, String *value)
{
    if (stack->top >= stack->maxsize) {
        printf("Stack overflow.\n");
        return;
    }
    stack->array[(stack->top)++] = value;
}

/**
 * @return
 * Returns the value popped or 0 if there is an 
 * underflow.
 * @note
 * The element still remains in the array even after
 * it is popped.
 * This function just returns the top value and returns
 * the top.
 * The top value can be overwritten when it is pushed.
 * It will also not be shown while printing...
 * So it is basically deleting...?
*/
String *pop(Queue *stack)
{
    if (stack->top <= 0) {
        printf("Stack underflow.\n");
        return NULL;
    }
    return stack->array[--(stack->top)];
}

void print_stack(const Queue *stack)
{
    printf("[");
    if (stack->top > 0)
        print_string(stack->array[0]);
    for (int i = 1; i < stack->top; ++i) {
        printf(", ");
        print_string(stack->array[i]);
    }
    printf("]\n");
}
