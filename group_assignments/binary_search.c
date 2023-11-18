#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int num, int start, int length)
{
    if (length < 1) return -1;
    else if (array[start+length/2] == num) return start+length/2;
    else if (array[start+length/2] > num) return binary_search(array, num, start, length/2);
    else return binary_search(array, num, start+(length/2)+1, length-(length/2)-1);
}

int main()
{
    int length, num;
    printf("Length of array: ");
    scanf("%d", &length);
    int *array = calloc(length, sizeof(int));
    printf("%d elements: ", length);
    for (int i = 0; i < length; ++i) scanf("%d", array+i);
    printf("Number to search: ");
    scanf("%d", &num);
    printf("Found %d at index %d.\n", num, binary_search(array, num, 0, length));
    return 0;
}
