#include <stdio.h>
#include <stdlib.h>

/**
 * @param a
 * Initialized by array[0].
 * @param b
 * Initialized by array[1].
 * @param k
 * Initialized by 1.
 * ka % b == 0 is checked.
 * @param index
 * Initialized by 2.
 * Because array[0] and array[1] are already passed in GCD.
 * @param length
 * Length will be length of array.
*/
int lcm_multiple(int a, int b, int k, int *array, int index, int length) {
    int r = (k*a) % b;
	if (r == 0 && index < length) 
        return lcm_multiple(k*a, array[index], 1, array, index+1, length);
	else if (r == 0) return k*a;
    return lcm_multiple(a, b, k+1, array, index, length);
}

int main()
{
    int *numbers, length;
    printf("Length of array: ");
    scanf("%d", &length);
    numbers = calloc(length, sizeof(int));
    printf("Numbers: ");
    for (int i = 0; i < length; ++i) scanf("%d", &numbers[i]);
    printf("Final lcm = %d\n", lcm_multiple(numbers[0], numbers[1], 1, numbers, 2, length));
    return 0;
}