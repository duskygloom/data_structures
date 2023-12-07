#include <math.h>
#include <stdio.h>

int mid_square_method(int key)
{
    const double A = 0.6180339887;
    const int m = 29;
    double product = key * A;
    return floor(m * (product - floor(product)));
}

int main()
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    printf("Hash: %d\n", mid_square_method(key));
    return 0;
}
