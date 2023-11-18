#include <stdio.h>

int main()
{
    int number, largest, smallest, comparison, length;

    printf("Number of elements: ");
    scanf("%d", &length);

    if (length < 1) return 0;
    printf("Elements: ");
    scanf("%d", &largest);

    for (int i = 0; i < length-1; ++i) {
        scanf("%d", &number);
        comparison = number > largest;
        largest = (number * comparison) + (largest * !comparison);
        comparison = number < smallest;
        smallest = (number * comparison) + (smallest * !comparison);
    }
    
    printf("Largest number: %d\nSmallest number: %d\n", largest, smallest);
    return 0;
}
