#include "stack.h"

#include <stdlib.h>

// #define DEBUG_MODE

Stack *create_stack(int maxsize)
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack) {
        stack->maxsize  = maxsize;
        stack->top      = -1;
        stack->array    = calloc(maxsize, sizeof(type));
    }
    #ifdef DEBUG_MODE
    printf("Created stack: %p(%d)\n", stack, maxsize);
    #endif
    return stack;
}

/**
 * @note
 * All the functions assume that the stack is not NULL.
*/

void delete_stack(Stack *stack)
{
    if (stack->array) free(stack->array);
    #ifdef DEBUG_MODE
    printf("Deleted stack: %p(%d)\n", stack, stack->maxsize);
    #endif
    free(stack);
}

void push(Stack *stack, type value)
{
    if (stack->top >= stack->maxsize-1) {
        printf("Stack overflow.\n");
        return;
    }
    stack->array[++stack->top] = value;
    #ifdef DEBUG_MODE
    printf("Pushing into stack: ");
    print_type(type);
    printf("->%d\n", stack->top);
    #endif
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
 * So it is basically deleting...?
*/
type pop(Stack *stack)
{
    if (stack->top < 0) {
        printf("Stack underflow.\n");
        return TYPE_NULL_VALUE;
    }
    #ifdef DEBUG_MODE
    printf("Popping from stack: ");
    print_type(stack->array[stack->top]);
    printf("->%d\n", stack->top);
    #endif
    return stack->array[stack->top--];
}

void print_stack(Stack *stack)
{
    printf("[");
    if (stack->top >= 0)
        print_type(stack->array[0]);
    for (int i = 1; i <= stack->top; ++i) {
        printf(", ");
        print_type(stack->array[i]);
    }
    printf("]\n");
}
