#include <stdio.h>
#include <stdlib.h>

void shift_element(int *array, int from, int to)
{
    int from_value = array[from];
    for (int i = from; i < to; ++i) array[i] = array[i+1];
    array[to] = from_value;
}

void quick_sort(int *array, int start, int count)
{
    if (count <= 1) return;
    int pivot = start + count - 1;
    for (int i = start; i < pivot; ++i) {
        if (array[i] > array[pivot]) {
            shift_element(array, i, pivot);
            --pivot;
            --i;
        }
    }
    quick_sort(array, start, pivot-start);
    quick_sort(array, pivot+1, start+count-pivot-1);
}

int main()
{
    int length, i;
    printf("Length of array: ");
    scanf("%d", &length);
    int *array = calloc(length, sizeof(int));
    printf("%d elements: ", length);
    for (i = 0; i < length; ++i) scanf("%d", array+i);
    quick_sort(array, 0, length);
    printf("Sorted array:");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
