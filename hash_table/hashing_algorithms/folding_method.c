#include <stdio.h>

int bsd_checksum(int key) {
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
    printf("Hash: %d\n", bsd_checksum(key));
    return 0;
}
