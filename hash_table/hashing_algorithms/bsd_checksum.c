#include <stdio.h>

typedef unsigned int uint;

uint bsd_checksum(const char *key) {
    uint hash = 0;
    while (*key) {
        hash = (hash >> 1) | ((hash & 1) << 16);
        hash += *key;
        hash &= 0xffff;
        ++key;
    }
    return hash;
}

int main()
{
    char key[20];
    printf("Key : ");
    scanf("%20s", key);
    printf("Hash: %d\n", bsd_checksum(key));
    return 0;
}
