#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

static inline void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int two_raised(int power)
{
    int value = 1;
    for (int i = 0; i < power; ++i)
        value *= 2;
    return value;
}

Heap *create_empty_heap(int length)
{
    Heap *heap = malloc(sizeof(Heap));
    heap->length = length;
    heap->array = calloc(length, sizeof(int));
    return heap;
}

Heap *create_heap_from_array(int *array, int length)
{
    Heap *heap = malloc(sizeof(Heap));
    heap->length = length;
    heap->array = array;
    return heap;
}

void delete_heap(Heap *heap)
{
    // free(heap->array);
    free(heap);
}

void print_heap(Heap *heap)
{
    int max_j = 1;
    for (int i = 0; i < heap->length;) {
        for (int j = 0; j < max_j && i+j < heap->length; ++j)
            printf("%d ", heap->array[i+j]);
        putchar('\n');
        i += max_j;
        max_j *= 2;
    }
}

void print_heap_array(Heap *heap)
{
    for (int i = 0; i < heap->length; ++i)
        printf("%d ", heap->array[i]);
    putchar('\n');
}

int count_levels(const Heap *heap)
{
    int n_branches = 0;
    while (two_raised(n_branches)-1 < heap->length) 
        ++n_branches;
    return n_branches;
}

void sort_heap(Heap *heap, int index)
{
    if (LEFT_CHILD(index) < heap->length) {                  // has 1 or 2 branches below
        sort_heap(heap, LEFT_CHILD(index));                  // recurssively reaches the bottom
        sort_heap(heap, RIGHT_CHILD(index));                 // before any operation is done
    }
    // ignore these cases
    if (index >= heap->length || LEFT_CHILD(index) >= heap->length) return;
    // variables to avoid long names
    int *parent = heap->array+index;
    int *left   = heap->array+LEFT_CHILD(index);
    int *right  = NULL;
    if (RIGHT_CHILD(index) < heap->length)
        right = heap->array+RIGHT_CHILD(index);
    // actual sorting
    if (*left > *parent && (!right || *left > *right)) {
        swap(parent, left);
        sort_path(heap, LEFT_CHILD(index));
    }
    else if (right && *right > *parent) {
        swap(parent, right);
        sort_path(heap, RIGHT_CHILD(index));
    }
}

void sort_path(Heap *heap, int index)
{
    // index not in heap or has no branch
    if (index >= heap->length || LEFT_CHILD(index) >= heap->length) return;
    // variables to avoid long names
    int *parent = heap->array+index;
    int *left   = heap->array+LEFT_CHILD(index);
    int *right  = NULL;
    if (RIGHT_CHILD(index) < heap->length)
        right = heap->array+RIGHT_CHILD(index);
    // actual sorting
    if (*left > *parent && (!right || *left > *right)) {
        swap(parent, left);
        sort_path(heap, LEFT_CHILD(index));
    }
    else if (right && *right > *parent) {
        swap(parent, right);
        sort_path(heap, RIGHT_CHILD(index));
    }
}
