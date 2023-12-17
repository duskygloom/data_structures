#ifndef MULTI_STACK_H
#define MULTI_STACK_H

#include <stdbool.h>

typedef struct StackInfo {
    int top;
    int size;                                               // how many elements it can store
    int length;                                             // how many elements it contains
} StackInfo;

StackInfo *create_stackinfo(int top, int size);

typedef struct MultiStack {
    int *array;
    int maxsize;
    int nstacks;
    StackInfo **info;
} MultiStack;

MultiStack *create_multistack(int nstacks, int initsize);
void delete_multistack(MultiStack *multistack);
void print_multistack(MultiStack *multistack);

int get_bottom(MultiStack *multistack, int stack);
bool isfull(MultiStack *multistack, int stack);
bool push(MultiStack *multistack, int stack, int value);
int pop(MultiStack *multistack, int stack);
int peek(MultiStack *multistack, int stack);
void print_stack(MultiStack *multistack, int stack);
int get_response(int nstacks, int initsize);

#endif
