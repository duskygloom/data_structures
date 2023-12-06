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

bool hash_insert(Node **table, Movie *movie)
{
    uint hash = hash_function(movie->name);
    if (table[hash] == NULL) {
        table[hash] = create_node(movie);
        return true;
    }
    Node *lastnode = table[hash];
    while (lastnode->next != NULL) {
        if (strcmp(lastnode->movie->name, movie->name) == 0)
            return false;
        #ifdef DEBUG_MODE
        check_collision(false);
        #endif
        lastnode = lastnode->next;
    }
    lastnode->next = create_node(movie);
    return true;
}

// #ifndef __cplusplus__strings__
// // case insensitive string comparison
// int stricmp(const char *str1, const char *str2)
// {
//     while (*str1 && *str2 && tolower(*str1++) == tolower(*str2++));
//     return *str1 - *str2;
// }
// #endif

Movie *hash_search(Node **table, char *moviename)
{
    uint hash = hash_function(moviename);
    Node *node = table[hash];
    while (node) {
        if (strcmp(node->movie->name, moviename) == 0)
            return node->movie;
        node = node->next;
    }
    return NULL;
}

void hash_print(Node **table)
{
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("Hash table: Element #%d\n", i);
        Node *node = table[i];
        while (node) {
            print_node(node);
            node = node->next;
        }
    }
}
