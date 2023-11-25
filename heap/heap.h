#ifndef HEAP_H
#define HEAP_H

/*
    These macros take an index and corresponding 
    index where its parent or children are.
*/
#define LEFT_CHILD(index)       2*index+1
#define RIGHT_CHILD(index)      2*index+2
#define PARENT_NODE(index)      (index-1)/2

typedef struct Heap {
    int length;
    int *array;
} Heap;

/**
 * @note
 * copies the content of array to Heap.array
*/
Heap *create_heap(int *array, int length);
void delete_heap(Heap *heap);
void print_heap(Heap *heap);

void heapify(Heap *heap);

#endif
