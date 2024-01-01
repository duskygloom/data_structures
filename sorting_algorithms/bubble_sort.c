#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int length)
{
    for (int i = 0; i < length-1; ++i)
        for (int j = 0; j < length-i-1; ++j)
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
}

void bubble_sort_desc(int *array, int length)
{
    for (int i = 0; i < length; ++i)
        for (int j = 0; j < length-i-1; ++j)
            if (array[j] < array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
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
    bubble_sort(array, length);
    printf("Sorted array (ascending):");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    bubble_sort_desc(array, length);
    printf("Sorted array (descending):");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
