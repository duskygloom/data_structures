#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
    // int dividend = a, divisor = b, remainder = a % b;
    // while (remainder != 0) {
    //     dividend = divisor;
    //     divisor = remainder;
    //     remainder = dividend % divisor;
    // }
    // return divisor;
}

int gcd_recursive(
    int *array, 
    int start1, int length1,
    int start2, int length2
) {
    if (length1 == 1 && length2 == 1) {
        // printf("GCD of array[%d] and array[%d].\n", start1, start2);
        return gcd(array[start1], array[start2]);
    }
    
    else if (length1 == 1) {
        // printf(
        //     "GCD of array[%d] and GCD of array(%d, %d) and array(%d, %d).\n", 
        //     start1, start2, length2/2, start2+length2/2, length2-length2/2
        // );
        return gcd(array[start1], 
            gcd_recursive(array, 
            start2, length2/2, start2+length2/2, length2-length2/2)
        );
    }

    else if (length2 == 1) {
        // printf(
        //     "GCD of array(%d, %d) and array(%d, %d) and GCD of array[%d].\n", 
        //     start1, length1/2, start1+length1/2, length1-length1/2, start2
        // );
        return gcd(gcd_recursive(array, 
            start1, length1/2, start1+length1/2, length1-length1/2), 
            array[start2]
        );
    }

    else {
        // printf(
        //     "GCD of array(%d, %d) and array(%d, %d) and GCD of array(%d, %d) and array(%d, %d).\n", 
        //     start1, length1/2, start1+length1/2, length1-length1/2, start2, length2/2, start2+length2/2, length2-length2/2
        // );
        return gcd(
            gcd_recursive(array, start1, length1/2, start1+length1/2, length1-length1/2), 
            gcd_recursive(array, start2, length2/2, start2+length2/2, length2-length2/2)
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
    printf("Final GCD = %d\n", gcd_recursive(numbers, 0, length/2, length/2, length-length/2));
    return 0;
}