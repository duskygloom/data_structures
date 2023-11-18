#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int length)
{
    int temp;
    for (int i = 1; i < length; ++i)
        for (int j = i-1; j >= 0; --j)
            if (array[j] > array[i]) {
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
    printf("Sorted array:");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
