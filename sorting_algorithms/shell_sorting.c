#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *array, int length)
{
    int temp, gap = length/2;
    while (gap > 1) {
        for (int i = 0; i < length-gap; i += 1) {
            while (array[i] > array[i+gap]) {
                temp = array[i];
                array[i] = array[i+gap];
                array[i+gap] = temp;
                --i;
            }
        }
        gap /= 2;
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
    shell_sort(array, length);
    printf("Sorted array:");
    for (i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
