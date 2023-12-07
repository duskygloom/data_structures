#include <stdio.h>

int count_digits(int n)
{
    int ndigits = 0;
    while (n != 0) {
        ++ndigits;
        n /= 10;
    }
    return ndigits;
}

int pow_10(int n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
        result *= 10;
    return result;
}

int int_slice(int n, int start, int length)
{
    n /= pow_10(count_digits(n)-start-length);
    n %= pow_10(length);
    return n;
}

int mid_square_method(int key)
{
    const int r = 2;
    int key_squared = key * key;
    int ndigits = count_digits(key_squared);
    int mid = (ndigits - r) / 2;
    return int_slice(key_squared, mid, r);
}

int main()
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    printf("Hash: %d\n", mid_square_method(key));
    return 0;
}
