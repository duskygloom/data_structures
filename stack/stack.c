#include "stack.h"

#include <stdlib.h>

Queue *create_stack(int maxsize)
{
    Queue *stack = malloc(sizeof(Queue));
    if (stack) {
        stack->maxsize  = maxsize;
        stack->top      = -1;
        stack->array    = calloc(maxsize, sizeof(int));
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

void push(Queue *stack, int value)
{
    if (stack->top >= stack->maxsize-1) {
        printf("Stack overflow.\n");
        return;
    }
    stack->array[++stack->top] = value;
}

/**
 * @return
 * Returns the value popped or -1 if there is an 
 * underflow.
 * @note
 * The element still remains in the array even after
 * it is popped.
 * This function just returns the top value and returns
 * the top.
 * The top value can be overwritten when it is pushed.
 * It will also not be shown while printing...
 * So it is basically deleting.
*/
int pop(Queue *stack)
{
    if (is_empty_stack(stack)) {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(Queue *stack)
{
    if (is_empty_stack(stack)) {
        printf("Empty stack.\n");
        return -1;
    }
    return stack->array[stack->top];
}

void print_stack(Queue *stack)
{
    printf("[");
    if (!is_empty_stack(stack))
        printf("%d", stack->array[stack->top]);
    for (int i = stack->top-1; i >= 0; --i) {
        printf(", %d", stack->array[i]);
    }
    printf("]\n");
}
