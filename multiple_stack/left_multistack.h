#ifndef MULTISTACK_H
#define MULTISTACK_H

#include <stdbool.h>

typedef struct Info {
    int top;
    int length;
} Info;

typedef struct MultiStack
{
    int *array;
    int nstacks, maxsize;
    Info **info;
} MultiStack;

MultiStack *create_multistack(int nstacks, int maxsize);
void delete_multistack(MultiStack *multistack);

void print_multistack(const MultiStack *multistack);
void print_stack(const MultiStack *multistack, int stack);
bool push(MultiStack *multistack, int stack, int value);
int pop(MultiStack *multistack, int stack);
int peek(MultiStack *multistack, int stack);
int count(MultiStack *multistack, int stack);

int get_response(int nstacks, int initsize);

#endif
