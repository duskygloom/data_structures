#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {20, 13, 15, 2, 0, 1, 5, 3, 6, 7, 9, 36, 37, 41, 20, 51};
    int length = sizeof(array)/sizeof(int);
    Heap *heap = create_heap_from_array(array, length);
    printf("Number of levels: %d\n", count_levels(heap));
    printf("Parent of %d is %d.\n", array[3], array[PARENT_NODE(3)]);
    printf("Children of %d are %d and %d.\n", array[3], array[LEFT_CHILD(3)], array[RIGHT_CHILD(3)]);
    printf("BEFORE SORTING\n");
    print_heap(heap);
    sort_heap(heap, 0);
    printf("AFTER SORTING\n");
    print_heap(heap);
    printf("Heap array: ");
    print_heap_array(heap);
    delete_heap(heap);
    return 0;
}
