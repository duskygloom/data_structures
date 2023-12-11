#include <stdio.h>
#include <stdlib.h>

/**
 * @param a
 * Initialized by array[0].
 * gcd(a, b).
 * @param b
 * Initialized by array[1].
 * gcd(a, b).
 * @param index
 * Initialized by 2.
 * Because array[0] and array[1] are already passed in GCD.
 * @param length
 * Length will be length of array.
*/
int gcd_multiple(int a, int b, int *array, int index, int length) {
    int r = a % b;
	if (r == 0 && index+1 < length) return gcd_multiple(b, array[index+1], array, index+1, length);
	else if (r == 0) return b;
    return gcd_multiple(b, a%b, array, index, length);
}

int main()
{
    int *numbers, length;
    printf("Length of array: ");
    scanf("%d", &length);
    numbers = calloc(length, sizeof(int));
    printf("Numbers: ");
    for (int i = 0; i < length; ++i) scanf("%d", &numbers[i]);
    printf("Final GCD = %d\n", gcd_multiple(numbers[0], numbers[1], numbers, 2, length));
    return 0;
}
