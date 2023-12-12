#include "left_multistack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Info *create_info()
{
    Info *info = malloc(sizeof(Info));
    if (!info) return NULL;
    info->top = 0;
    info->length = 0;
    return info;
}

MultiStack *create_multistack(int nstacks, int maxsize)
{
    MultiStack *multistack = malloc(sizeof(MultiStack));
    if (!multistack) return NULL;
    multistack->nstacks = nstacks;
    multistack->maxsize = maxsize;
    multistack->array = calloc(maxsize, sizeof(int));
    if (!multistack->array) {
        delete_multistack(multistack);
        return NULL;
    }
    multistack->info = calloc(nstacks, sizeof(Info));
    if (!multistack->info) {
        delete_multistack(multistack);
        return NULL;
    }
    Info *info;
    for (int i = 0; i < nstacks; ++i) {
        info = create_info();
        if (!info) {
            delete_multistack(multistack);
            return NULL;
        }
        multistack->info[i] = info;
    }
    return multistack;
}

void delete_multistack(MultiStack *multistack)
{
    if (!multistack) return;
    if (multistack->array) free(multistack->array);
    if (multistack->info) {
        for (int i = 0; i < multistack->nstacks; ++i)
            if (multistack->info[i]) free(multistack->info[i]);
        free(multistack->info);
    }
    free(multistack);
}

void print_multistack(const MultiStack *multistack)
{
    putchar('[');
    if (multistack->maxsize > 0) printf("%d", multistack->array[0]);
    for (int i = 1; i < multistack->maxsize; ++i)
        printf(", %d", multistack->array[i]);
    printf("]\n");
}

/**
 * @return
 * Returns the number of empty slots at the end
 * of the multiple stack.
*/
int get_empty_slots(const MultiStack *multistack)
{
    Info *info = multistack->info[multistack->nstacks-1];
    return multistack->maxsize - (info->top + info->length);
}

bool is_invalid_stack(const MultiStack *multistack, int stack)
{
    if (stack < 0 || stack >= multistack->nstacks) {
        printf("[Error] Invalid stack number. (%d)\n", multistack->nstacks);
        return true;
    }
    return false;
}

bool is_empty_stack(const MultiStack *multistack, int stack)
{
    if (is_invalid_stack(multistack, stack)) return true;                   // empty if invalid
    Info *info = multistack->info[stack];
    return info->length <= 0;
}

void print_stack(const MultiStack *multistack, int stack)
{
    if (is_invalid_stack(multistack, stack)) return;
    int top = multistack->info[stack]->top;
    int length = multistack->info[stack]->length;
    putchar('[');
    if (length > 0) printf("%d", multistack->array[top]);
    for (int i = 1; i < length; ++i)
        printf(", %d", multistack->array[top+i]);
    printf("]\n");
}

bool push(MultiStack *multistack, int stack, int value)
{
    if (is_invalid_stack(multistack, stack)) return false;
    // checking empty slots and overflow
    int empty_slots = get_empty_slots(multistack);
    if (empty_slots <= 0) {
        printf("[Alert] Overflow. (%d)\n", value);
        return false;
    }
    int top = multistack->info[stack]->top;
    int length = multistack->info[stack]->length;
    // shifting chunks of int to right
    int *source = multistack->array + (top + length);
    int range = multistack->maxsize - top - length - empty_slots;
    memmove(source+1, source, range*sizeof(int));
    // making changes to the info of stacks
    for (int i = stack+1; i < multistack->nstacks; ++i)
        ++(multistack->info[i]->top);
    ++(multistack->info[stack]->length);
    *source = value;
    return true;
}

int pop(MultiStack *multistack, int stack)
{
    if (is_invalid_stack(multistack, stack)) return -1;
    // checking for underflow
    if (is_empty_stack(multistack, stack)) {
        printf("[Alert] Underflow. (%d)\n", stack);
        return false;
    }
    int top = multistack->info[stack]->top;
    int length = multistack->info[stack]->length;
    int empty_slots = get_empty_slots(multistack);
    // shifting chunks of int towards left
    int *source = multistack->array + (top + length);
    int range = multistack->maxsize - top - length - empty_slots;
    int popped = *source;
    memmove(source-1, source, range*sizeof(int));
    // making changes to the info of stacks
    for (int i = stack+1; i < multistack->nstacks; ++i)
        --(multistack->info[i]->top);
    --(multistack->info[stack]->length);
    return popped;
}

int peek(MultiStack *multistack, int stack)
{
    if (is_invalid_stack(multistack, stack)) return -1;
    if (is_empty_stack(multistack, stack)) {
        printf("[Alert] Underflow. (%d)\n", stack);
        return -1;
    }
    int top = multistack->info[stack]->top;
    return multistack->array[top];
}

int count(MultiStack *multistack, int stack)
{
    if (is_invalid_stack(multistack, stack)) return -1;
    if (is_empty_stack(multistack, stack)) {
        printf("[Alert] Underflow. (%d)\n", stack);
        return -1;
    }
    int length = multistack->info[stack]->length;
    return length;
}

int get_response(int nstacks, int initsize)
{
    printf("\n***** Multiple Stack (%d, %d) *****\n", nstacks, initsize);
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Peek.\n");
    printf("4. Print stack.\n");
    printf("5. Print multistack.\n");
    printf("6. Quit.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}
