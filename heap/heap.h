#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef struct Heap {
    int length;
    int *array;
} Heap;

int two_raised(int power);

Heap *create_empty_heap(int length);
Heap *create_heap_from_array(int *array, int length);
/**
 * @note
 * free heap.array on your own
*/
void delete_heap(Heap *heap);
void print_heap(Heap *heap);
void print_heap_array(Heap *heap);

/*
    These macros take an index and corresponding 
    index where its parent or children are.
*/
#define LEFT_CHILD(index)       2*index+1
#define RIGHT_CHILD(index)      2*index+2
#define LEFT_SIBLING(index)     index-1
#define RIGHT_SIBLING(index)    index+1
#define PARENT_NODE(index)      (index-1)/2

int count_levels(const Heap *heap);

/**
 * @param heap
 * the heap struct which contains array and length of the heap
 * @param index
 * the index of the root since it is a recurssive algorithm
 * at initializing time root = 0
*/
void sort_node_left(Heap *heap, int index);
void sort_node_parent(Heap *heap, int index);

/**
 * @note
 * the previous functions sort from bottom to top
 * but this function sorts from top to bottom
*/
void sort_down(Heap *heap, int index);

#endif
