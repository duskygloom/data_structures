#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MultiStack {
    int *array;
    int maxsize;
    int nstacks;
} MultiStack;

typedef struct StackInfo {
    int top;
    int length;
} StackInfo;

MultiStack *create_multistack(int nstacks, int defaultsize) 
{
    int maxsize = nstacks*defaultsize;
    MultiStack *multistack = malloc(sizeof(MultiStack));
    multistack->array = calloc(maxsize, sizeof(int));
    multistack->maxsize = maxsize;
    multistack->nstacks = nstacks;
    return multistack;
}

void delete_multistack(MultiStack *multistack) 
{
    if (multistack) {
        if (multistack->array) free(multistack->array);
        free(multistack);
    }
}

void print_multistack(MultiStack *multistack, StackInfo *info)
{
    int maxsize = multistack->maxsize;
    putchar('[');
    if (maxsize > 0) printf("%d", multistack->array[0]);
    for (int i = 1; i < maxsize; ++i)
        printf(", %d", multistack->array[i]);
    printf("]\n");
}

bool push(MultiStack *multistack, StackInfo *info, int stack, int value)
{
    int top = info[stack].top;
    int length = info[stack].length;
    int maxsize = multistack->maxsize;
    if (top+length >= info[(stack+1)%maxsize].top) {
        // next empty stack
        for (int i = 0; i < multistack->nstacks-1; ++i) {
            if (top+length < info[(stack+i)%maxsize].top) {
                // do something
            }
        }
    }
    multistack->array[top] = value;
    ++(info[stack].top);
    ++(info[stack].length);
}

int pop(MultiStack *multistack, StackInfo *info, int stack)
{
    int top = info[stack].top;
    int length = info[stack].length;
    if (length <= 0) return -1;
    int popped = multistack->array[top];
    --(info[stack].top);
    --(info[stack].length);
    return popped;
}

int peek(MultiStack *multistack, struct StackInfo *info, int stack)
{
    if (info[stack].length == 0) return -1;
    return multistack->array[info[stack].top];
}

void display(MultiStack *multistack, struct StackInfo *info, int stack)
{
    int top = info[stack].top;
    int length = info[stack].length;
    int maxsize = multistack->maxsize;
    for (int i = 0; i < length; ++i)
        printf("%d ", multistack[(top+i)%maxsize]);
    putchar('\n');
}

int main()
{
    int nstacks = 4;
    int defaultsize = 5;
    // creating multistack
    MultiStack *multistack = create_multistack(nstacks, defaultsize);
    // creating stack info
    StackInfo *stackinfo = calloc(nstacks, sizeof(StackInfo));
    // initializing stack info
    for (int i = 0; i < nstacks; ++i) {
        stackinfo[i].top = i * defaultsize;
        stackinfo[i].length = 0;
    }

    free(stackinfo);
    free(multistack);
    return 0;
}