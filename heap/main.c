#include "heap.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int array[] = {20, 13, 15, 2, 0, 1, 5, 3, 6, 7, 9, 36, 37, 41, 20, 51};
    // int array[] = {15, 17, 11, 9, 52, 26, 13, 72, 90, 55, 49, 12};
    int array[] = {30, 45, 15, 17, 13, 11, 21, 32, 9, 7, 56, 72};
    int length = sizeof(array)/sizeof(int);
    Heap *heap = create_heap(array, length);
    printf("Parent of %d is %d.\n", array[3], array[PARENT_NODE(3)]);
    printf("Children of %d are %d and %d.\n", array[3], array[LEFT_CHILD(3)], array[RIGHT_CHILD(3)]);
    printf("\nBEFORE SORTING\n");
    print_heap(heap);
    heapify(heap);
    printf("\nAFTER SORTING\n");
    print_heap(heap);
    delete_heap(heap);
    return 0;
}
