#include <stdio.h>

int mid_square_method(int key)
{
    const int m = 29;
    return key % m;
}

int main()
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    printf("Hash: %d\n", mid_square_method(key));
    return 0;
}
