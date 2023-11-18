#include <stdio.h>
#include <stdlib.h>

void merge_sorted_subarrays(
    int *array, int start1, int size1, int start2, int size2
) {
    // considering the subarrays are next to each other
    // which is indeed the case during merge sort
    int index1 = start1;
    int index2 = start2;
    int temp, i;
    while (index2 < start2+size2) {
        // printf("comparing array[%d] and array[%d]\n", index1, index2);
        if (array[index2] < array[index1]) {
            // printf("array[%d] <-> array[%d]\n", index1, index2);
            for (i = index2-index1; i > 0 ; --i) {
                // printf("  array[%d] <-> array[%d]\n", index1+i, index1+i-1);
                temp = array[index1+i];
                array[index1+i] = array[index1+i-1];
                array[index1+i-1] = temp;
            }
            // printf("Array:");
            // for (i = 0; i < size1+size2; ++i) printf(" %d", array[i]);
            // putchar('\n');
            ++index1;
            ++index2;
        } else ++index1;
    }
}

void merge_sort(int *array, int start, int size)
{
    if (size == 1) return;
        // printf(
        //     "merge sorting array[%d:%d] and array[%d:%d]\n", 
        //     start, 
        //     start+size/2, 
        //     start+size/2, 
        //     start+size
        // );
        merge_sort(array, start, size/2);
        merge_sort(array, start+size/2, size-size/2);
        merge_sorted_subarrays(array, start, size/2, start+size/2, size-size/2);
}

int main() 
{
    int length, *array, i;
    printf("Number of elements: ");
    scanf("%d", &length);
    array = calloc(length, sizeof(int));
    printf("Elements: ");
    for (i = 0; i < length; ++i) scanf("%d", array+i);

    merge_sort(array, 0, length);
    printf("Sorted array:");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');

    // int i, array[] = {1, 4, 5, 3, 4, 6, 7};
    // merge_sort(array, 7);

    // printf("Output:");
    // for (i = 0; i < 7; ++i) printf(" %d", array[i]);
    // putchar('\n'); 3 3 6 5 6 7

    return 0;
}
