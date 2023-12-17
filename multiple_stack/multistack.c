#include "multistack.h"

#include <stdio.h>
#include <stdlib.h>

StackInfo *create_stackinfo(int top, int size)
{
    StackInfo *info = malloc(sizeof(StackInfo));
    if (!info) return NULL;
    info->top = top;
    info->size = size;
    info->length = 0;
    return info;
}

MultiStack *create_multistack(int nstacks, int initsize)
{
    int maxsize = nstacks*initsize;
    MultiStack *multistack = malloc(sizeof(MultiStack));
    if (!multistack) return NULL;
    multistack->array = calloc(maxsize, sizeof(int));
    multistack->maxsize = maxsize;
    multistack->nstacks = nstacks;
    multistack->info = calloc(nstacks, sizeof(StackInfo *));
    if (!multistack->info) {
        free(multistack);
        return NULL;
    }
    // initializing stack info
    StackInfo **stackinfo = multistack->info;
    for (int i = 0; i < nstacks; ++i)
        stackinfo[i] = create_stackinfo(i*initsize, initsize);
    return multistack;
}

void delete_multistack(MultiStack *multistack) 
{
    if (multistack == NULL) return;
    if (multistack->array) free(multistack->array);
    if (multistack->info) {
        for (int i = 0; i < multistack->nstacks; ++i)
            if (multistack->info[i]) free(multistack->info[i]);
        free(multistack->info);
    }
    free(multistack);
}

void print_multistack(MultiStack *multistack)
{
    int maxsize = multistack->maxsize;
    putchar('[');
    if (maxsize > 0) printf("%d", multistack->array[0]);
    for (int i = 1; i < maxsize; ++i)
        printf(", %d", multistack->array[i]);
    printf("]\n");
}

/**
 * @note
 * The bottom returned may be bigger than maxsize.
 * So use with modulo when needed.
*/
int get_bottom(MultiStack *multistack, int stack)
{
    StackInfo **info = multistack->info;
    int top = info[stack]->top;
    int length = info[stack]->length;
    return top + length;
}

bool isfull(MultiStack *multistack, int stack)
{
    StackInfo **info = multistack->info;
    int maxsize = multistack->maxsize;
    int nexttop = info[(stack+1)%multistack->maxsize]->top;
    return get_bottom(multistack, stack) % maxsize >= nexttop;
}

bool push(MultiStack *multistack, int stack, int value)
{
    StackInfo **info = multistack->info;
    int top = info[stack]->top;
    int maxsize = multistack->maxsize;
    int nstacks = multistack->nstacks;
    int nextstack;
    if (isfull(multistack, stack)) {
        // next empty stack
        for (int i = 1; i < nstacks; ++i) {
            nextstack = (stack+i)%nstacks;
            if (!isfull(multistack, nextstack)) {
                int bottom = get_bottom(multistack, stack);
                int emptybottom = get_bottom(multistack, nextstack);
                for (int j = emptybottom-1; j >= bottom; --j)
                    multistack->array[(j+1)%maxsize] = multistack->array[j%maxsize];
                // changing tops
                int stacktop;
                for (int j = i; j >= 0; --j) {
                    stacktop = info[(stack+i)%maxsize]->top;
                    if (stacktop-1 < 0)
                        info[(stack+i)%maxsize]->top = maxsize-1;
                    else --(info[(stack+i)%maxsize]->top);
                }
                break;
            }
        }
    }
    if (isfull(multistack, stack)) return false;
    multistack->array[top] = value;
    ++(info[stack]->top);
    ++(info[stack]->length);
    return true;
}

int pop(MultiStack *multistack, int stack)
{
    StackInfo **info = multistack->info;
    int top = info[stack]->top;
    int length = info[stack]->length;
    if (length <= 0) return -1;
    int popped = multistack->array[top];
    --(info[stack]->top);
    --(info[stack]->length);
    return popped;
}

int peek(MultiStack *multistack, int stack)
{
    StackInfo **info = multistack->info;
    if (info[stack]->length == 0) return -1;
    return multistack->array[info[stack]->top];
}

void print_stack(MultiStack *multistack, int stack)
{
    StackInfo **info = multistack->info;
    int top = info[stack]->top;
    int size = info[stack]->size;
    int maxsize = multistack->maxsize;
    putchar('[');
    if (size > 0) printf("%d", multistack->array[top]);
    for (int i = 1; i < size; ++i)
        printf(", %d", multistack->array[(top+i)%maxsize]);
    printf("]\n");
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

