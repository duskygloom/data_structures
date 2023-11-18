#include <stdio.h>

void sort_ascending(int arr[], int len)
{
    int i, j, temp;
    for (i = 1; i < len; ++i)
        for (j = i-1; j >= 0; --j)
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                --i;
            }
}

int main()
{
    int array[] = { 23, 4142135, 15, 32543, 643, 652 , 7713, 53726 };
    int length = 8;
    sort_ascending(array, length);
    printf("Ascending array:");
    for (int i = 0; i < length; ++i) printf(" %d", array[i]);
    putchar('\n');
    return 0;
}
