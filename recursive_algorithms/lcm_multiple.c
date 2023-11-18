#include <stdio.h>
#include <stdlib.h>

int lcm(int a, int b, int multiple) {
    // multiple is multiple of a
    if (multiple % b == 0) return multiple;
    return lcm(a, b, multiple+a);
}

int lcm_recursive(
    int *array, 
    int start1, int length1,
    int start2, int length2
) {
    if (length1 == 1 && length2 == 1) {
        // printf("lcm of array[%d] and array[%d].\n", start1, start2);
        return lcm(array[start1], array[start2], array[start1]);
    }
    
    else if (length1 == 1) {
        // printf(
        //     "lcm of array[%d] and lcm of array(%d, %d) and array(%d, %d).\n", 
        //     start1, start2, length2/2, start2+length2/2, length2-length2/2
        // );
        return lcm(array[start1], 
            lcm_recursive(array, 
            start2, length2/2, start2+length2/2, length2-length2/2),
            array[start1]
        );
    }

    else if (length2 == 1) {
        // printf(
        //     "lcm of array(%d, %d) and array(%d, %d) and lcm of array[%d].\n", 
        //     start1, length1/2, start1+length1/2, length1-length1/2, start2
        // );
        return lcm(array[start2],
            lcm_recursive(array, 
            start1, length1/2, start1+length1/2, length1-length1/2), 
            array[start2]
        );
    }

    else {
        // printf(
        //     "lcm of array(%d, %d) and array(%d, %d) and lcm of array(%d, %d) and array(%d, %d).\n", 
        //     start1, length1/2, start1+length1/2, length1-length1/2, start2, length2/2, start2+length2/2, length2-length2/2
        // );
        int lcm_value = lcm_recursive(array, start1, length1/2, start1+length1/2, length1-length1/2);
        return lcm(
            lcm_value,
            lcm_recursive(array, start2, length2/2, start2+length2/2, length2-length2/2),
            lcm_value
        );
    }
}

int main()
{
    int *numbers, length;
    printf("Length of array: ");
    scanf("%d", &length);
    numbers = calloc(length, sizeof(int));
    printf("Numbers: ");
    for (int i = 0; i < length; ++i) scanf("%d", &numbers[i]);
    printf("Final lcm = %d\n", lcm_recursive(numbers, 0, length/2, length/2, length-length/2));
    return 0;
}