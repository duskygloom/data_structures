#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *array, int length)
{
    if (length <= 1) return;
    int min_index, temp, i, j;
    for (i = 0; i < length-1; ++i) {
        min_index = i;
        for (j = i+1; j < length; ++j)
            if (array[j] < array[min_index]) min_index = j;
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
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
    selection_sort(array, length);
    printf("Sorted array:");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
