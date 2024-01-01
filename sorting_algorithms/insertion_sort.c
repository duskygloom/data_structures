#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int length)
{
    int temp;
    for (int i = 1; i < length; ++i)
        for (int j = i-1; j >= 0; --j)
            if (array[i] < array[j]) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                --i;
            }
}

void insertion_sort_descending(int *array, int length)
{
    int temp;
    for (int i = 1; i < length; ++i)
        for (int j = i-1; j >= 0; --j)
            if (array[i] > array[j]) {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                --i;
            }
}

int main()
{
    int length, i;
    printf("Length of array: ");
    scanf("%d", &length);
    int *array = calloc(length, sizeof(int));
    printf("%d elements: ", length);
    for (i = 0; i < length; ++i) scanf("%d", array+i);
    insertion_sort(array, length);
    printf("Sorted array (ascending):");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    insertion_sort_descending(array, length);
    printf("Sorted array (descending):");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
