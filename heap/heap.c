#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @returns
 * 1 if index is a left child
 * else 0
*/
#define IS_LEFT_CHILD(index)    (index%2)

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

/**
 * @todo
 * the current node is the left node in this implementation
 * but ran across a problem so its buggy for now
*/
void sort_node_left(Heap *heap, int index)
{
    if (LEFT_CHILD(index) < heap->length) {
        sort_node_left(heap, LEFT_CHILD(index));
        sort_node_left(heap, RIGHT_CHILD(index));
    }
    // ignore these cases
    if ((index == 0 && index < heap->length) || !IS_LEFT_CHILD(index)) return;
    // variables to avoid long names
    int *left = heap->array+index;
    int *parent = heap->array+PARENT_NODE(index);
    int *right = NULL;
    if (RIGHT_SIBLING(index) < heap->length)
        right = heap->array+RIGHT_SIBLING(index);
    // actual sorting
    if (*parent < *left && (!right || *left > *right)) {
        swap(parent, left);
    }
    else if (right && *parent < *right) {
        swap(parent, right);
    }
}

/**
 * @todo
 * the current node is the left node in this implementation
 * but ran across a problem so its buggy for now
 * @todo
 * when a node is changed, the nodes below
 * should also be checked and changed
*/
void sort_node_parent(Heap *heap, int index)
{
    if (LEFT_CHILD(index) < heap->length) {                         // has 1 or 2 branches below
        sort_node_parent(heap, LEFT_CHILD(index));                         // recurssively reaches the bottom
        sort_node_parent(heap, RIGHT_CHILD(index));                        // before any operation is done
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
        sort_down(heap, LEFT_CHILD(index));
    }
    else if (right && *right > *parent) {
        swap(parent, right);
        sort_down(heap, RIGHT_CHILD(index));
    }
}

void sort_down(Heap *heap, int index)
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
        sort_down(heap, LEFT_CHILD(index));
    }
    else if (right && *right > *parent) {
        swap(parent, right);
        sort_down(heap, RIGHT_CHILD(index));
    }
}
