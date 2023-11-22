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
#define PARENT_NODE(index)      (index-1)/2

int count_levels(const Heap *heap);

/**
 * @param heap
 * the heap struct which contains array and length of the heap
 * @param index
 * the index of the root since it is a recurssive algorithm
 * at initializing time root = 0
*/
void sort_heap(Heap *heap, int index);

/**
 * @note
 * this function sorts the entire path below the
 * index ensuring the path follows heap structure
*/
void sort_path(Heap *heap, int index);

#endif
