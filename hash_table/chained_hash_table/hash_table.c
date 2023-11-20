#include "hash_table.h"

#include <ctype.h>
#include <string.h>

uint hash_function(char *key)
{
    uint hash = 0;
    while (*key) {
        hash = (hash >> 1) | ((hash & 1) << 31);
        hash += *key++;
        hash &= 0xffffffff;
    }
    return hash % TABLE_SIZE;
}

void check_collision(bool print_collision)
{
    static int collisions = 0;
    if (print_collision) printf("Collisions: %d\n", collisions);
    else ++collisions;
}

bool hash_insert(Node **table, Node *node)
{
    uint index = hash_function(node->movie->name);
    if (!table[index]) {
        table[index] = node;
        return true;
    }
    return insert_node(table[index], node);
}

// #ifndef __cplusplus__strings__
// // case insensitive string comparison
// int stricmp(const char *str1, const char *str2)
// {
//     while (*str1 && *str2 && tolower(*str1++) == tolower(*str2++));
//     return *str1 - *str2;
// }
// #endif

Movie *hash_search(Node **table, char *movie_name)
{
    uint index = hash_function(movie_name);
    Node *curr = table[index];
    while (curr) {
        if (strcmp(curr->movie->name, movie_name) == 0)
            return curr->movie;
        curr = curr->next;
    }
    return NULL;
}

void hash_print(Node **table)
{
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("Hash table: Element #%d\n", i);
        Node *curr = table[i];
        while (curr) {
            print_node(curr);
            curr = curr->next;
        }
    }
}
