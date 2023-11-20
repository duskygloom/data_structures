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
    free(table);
}

bool hash_insert(HashTable *table, Movie *movie)
{
    if (table->length >= LOAD_FACTOR*TABLE_SIZE) 
        return false;
    uint hash = hash_function(movie->name);
    int i, index;
    Movie **array = table->array;
    for (i = 0; i < TABLE_SIZE; ++i) {
        index = (hash+i)%TABLE_SIZE;
        if (array[index] && strcmp(array[index]->name, movie->name) == 0)
            return false;
        else if (!array[index]) {
            array[index] = movie;
            ++table->length;
            return true;
        }
        check_collision(false);
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

int hash_search(HashTable *table, char *movie_name)
{
    uint hash = hash_function(movie_name);
    int i, index = hash;
    Movie **array = table->array;
    for (i = 0; i < TABLE_SIZE; ++i) {
        index = (hash+i)%TABLE_SIZE;
        if (array[index] && strcmp(array[index]->name, movie_name) == 0)
            return index;
    }
    return -1;
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
