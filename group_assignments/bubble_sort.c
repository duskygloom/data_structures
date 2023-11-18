#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int length)
{
    int temp;
    for (int i = length-1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
}

int main()
{
    int length;
    printf("Length of array: ");
    scanf("%d", &length);
    int *array = calloc(length, sizeof(int));
    printf("%d elements: ", length);
    for (int i = 0; i < length; ++i) scanf("%d", array+i);
    bubble_sort(array, length);
    printf("Sorted array:");
    for (int i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
