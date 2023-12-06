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

HashTable *create_hash_table(void) 
{
    HashTable *hashtable = malloc(sizeof(HashTable));
    hashtable->length = 0;
    hashtable->array = calloc(TABLE_SIZE, sizeof(Movie *));
    return hashtable;
}

void delete_hash_table(HashTable *table)
{
    // for (int i = 0; i < NUM_MOVIES; ++i)
    //     delete_movie(hashtable->array[i]);
    if (table) {
        if (table->array) free(table->array);
        free(table);
    }
}

bool hash_insert(HashTable *table, Movie *movie)
{
    if (table->length >= LOAD_FACTOR*TABLE_SIZE) 
        return false;
    uint hash = hash_function(movie->name);
    int offset = 0, index;
    Movie **array = table->array;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        offset = i*i;
        index = (hash+offset)%TABLE_SIZE;
        if (array[index] && strcmp(array[index]->name, movie->name) == 0)
            return false;
        else if (array[index] == NULL) {
            array[index] = movie;
            ++(table->length);
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

Movie *hash_search(HashTable *table, char *moviename)
{
    uint hash = hash_function(moviename);
    int offset = 0, index;
    Movie **array = table->array;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        offset = i*i;
        index = (hash+offset)%TABLE_SIZE;
        if (array[index] && strcmp(array[index]->name, moviename) == 0)
            return array[index];
    }
    return NULL;
}

void hash_print(HashTable *table)
{
    Movie **array = table->array;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("Element #%d: ", i);
        if (array[i]) print_movie(array[i]);
        else puts("---");
    }
}
