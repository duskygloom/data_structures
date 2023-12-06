#include "hash_table.h"

// #include <ctype.h>
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

HashTable *create_hashtable()
{
    HashTable *hashtable = malloc(sizeof(HashTable));
    hashtable->length = 0;
    hashtable->table = calloc(TABLE_SIZE, sizeof(Node *));
    return hashtable;
}

void delete_hashtable(HashTable *hashtable)
{
    if (hashtable) {
        if (hashtable->table) {
            for (int i = 0; i < TABLE_SIZE; ++i)
                free(hashtable->table[i]);
            free(hashtable->table);
        }
        free(hashtable);
    }
}

void print_hashtable(HashTable *hashtable)
{
    Node **table = hashtable->table;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("Hash table: Element #%d\n", i);
        if (table[i]) print_node(table[i]);
        else printf("---\n");
    }
}

bool hash_insert(HashTable *hashtable, Movie *movie)
{
    if (hashtable->length > LOAD_FACTOR*TABLE_SIZE) 
        return false;
    uint hash = hash_function(movie->name);
    Node **table = hashtable->table;
    if (table[hash] == NULL) {
        table[hash] = create_node(movie);
        ++(hashtable->length);
        return true;
    }
    Node **lastnode_ptr = &table[hash];
    while ((*lastnode_ptr)->next) {
        if (strcmp((*lastnode_ptr)->movie->name, movie->name) == 0)
            return false;
        #ifdef DEBUG_MODE
        check_collision(false);
        #endif
        lastnode_ptr = &((*lastnode_ptr)->next);
    }
    int lastindex = lastnode_ptr - table, offset = 0, index;
    for (; offset < TABLE_SIZE; ++offset) {
        index = (lastindex+offset)%TABLE_SIZE;
        if (table[index] == NULL) {
            table[index] = create_node(movie);
            (*lastnode_ptr)->next = table[index];
            ++(hashtable->length);
            return true;
        }
        #ifdef DEBUG_MODE
        check_collision(false);
        #endif
    }
    return false;
}

// #ifndef __cplusplus__strings__
// // case insensitive string comparison
// int stricmp(const char *str1, const char *str2)
// {
//     while (*str1 && *str2 && tolower(*str1++) == tolower(*str2++));
//     return *str1 - *str2;
// }
// #endif

Movie *hash_search(HashTable *hashtable, char *moviename)
{
    uint hash = hash_function(moviename);
    Node **table = hashtable->table;
    Node *node = table[hash];
    while (node) {
        if (strcmp(node->movie->name, moviename) == 0)
            return node->movie;
        node = node->next;
    }
    return NULL;
}
