#include "heap.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @details
 * defines when to replace with left
 * else replaces with right
 * @note
 * modify this to change the condition
 * for heapify
 * @note
 * parent left and right must pointers
 * not values
*/
static inline bool replace_left(int *parent, int *left, int *right)
{
    // max heap
    return (bool)(left && *left > *parent && (!right || *left > *right));
    // min heap
    // return (bool)(left && *left < *parent && (!right || *left < *right));
}

/**
 * @note
 * it is assumed that REPLACE_WITH_LEFT is already checked
 * so REPLACE_WITH_RIGHT should be used in a else if statement
 * after REPLACE_WITH_LEFT
*/
static inline bool replace_right(int *parent, int *left, int *right)
{
    // max heap
    return (bool)(right && *right > *parent);
    // min heap
    // return (bool)(right && *right < *parent);
}

static inline void swap(int *a, int *b)
{
    int val = *a;
    *a      = *b;
    *b      = val;
}

Heap *create_heap(int *array, int length)
{
    Heap *heap      = malloc(sizeof(Heap));
    heap->length    = length;
    heap->array     = calloc(length, sizeof(int));
    memcpy(heap->array, array, length*sizeof(int));
    return heap;
}

void delete_heap(Heap *heap)
{
    free(heap->array);
    free(heap);
}

void print_heap(Heap *heap)
{
    int index = 0;
    for (int i = 1; ; i*=2) {
        for (int j = 0; j < i && index < heap->length; ++j) {
            printf("%d ", heap->array[index++]);
        }
        putchar('\n');
        if (index >= heap->length) break;
    }
}

/**
 * @return
 * returns the index of the node it has been replaced with
 * if not replaced, returns -1
*/
void replace_with_children(Heap *heap, int index)
{
    // returns if no children
    if (LEFT_CHILD(index) >= heap->length) return;
    int *parent = heap->array+index;
    int *left   = heap->array+LEFT_CHILD(index);
    int *right  = NULL;
    if (RIGHT_CHILD(index) < heap->length)
        right   = heap->array+RIGHT_CHILD(index);
    if (replace_left(parent, left, right)) {
        swap(left, parent);
        replace_with_children(heap, LEFT_CHILD(index));
    }
    else if (replace_right(parent, left, right)) {
        swap(right, parent);
        replace_with_children(heap, RIGHT_CHILD(index));
    }
}

void heapify(Heap *heap)
{
    /*
        last intermediate node is the parent node of
        the last node (length - 1)
        = (length - 1 - 1) / 2
        = (length - 2) / 2
    */
    for (int i = (heap->length-2)/2; i >= 0; --i)
        replace_with_children(heap, i);
}
