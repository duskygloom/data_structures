#include <stdio.h>

int folding_method(int key) {
    const int m = 29;
    int hash = 0;
    while (key > 0) {
        hash += key % m;
        key /= m;
    }
    return hash % m;
}

int main()
{
    int key;
    printf("Key : ");
    scanf("%d", &key);
    printf("Hash: %d\n", folding_method(key));
    return 0;
}
