#include <stdio.h>

int main()
{
    int number, largest, comparison, length;

    printf("Number of elements: ");
    scanf("%d", &length);

    if (length < 1) return 0;
    printf("Elements: ");
    scanf("%d", &largest);

    for (int i = 0; i < length-1; ++i) {
        scanf("%d", &number);

        comparison = number > largest;
        largest = (number * comparison) + (largest * !comparison);
    }
    
    printf("Largest number: %d\n", largest);
    return 0;
}
