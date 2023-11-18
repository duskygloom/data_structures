#include <stdio.h>

int main()
{
    int number, smallest, comparison, length;

    printf("Number of elements: ");
    scanf("%d", &length);

    if (length < 1) return 0;
    printf("Elements: ");
    scanf("%d", &smallest);

    for (int i = 0; i < length-1; ++i) {
        scanf("%d", &number);

        comparison = number < smallest;
        smallest = (number * comparison) + (smallest * !comparison);
    }
    
    printf("Smallest number: %d\n", smallest);
    return 0;
}
