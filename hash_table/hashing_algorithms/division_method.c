#include <stdio.h>

int division_method(int key)
{
    const int m = 29;
    return key % m;
}

int main()
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    printf("Hash: %d\n", division_method(key));
    return 0;
}
