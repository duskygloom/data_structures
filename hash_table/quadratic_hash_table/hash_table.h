#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE          503
#define NUM_MOVIES          250
#define MOVIE_FILE          "top_english_movies.csv"
#define LOAD_FACTOR         0.5

// #define DEBUG_MODE

#include "movie.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;
uint hash_function(char *key);

void check_collision(bool print_collision);

typedef struct HashTable {
    int length;
    Movie **array;
} HashTable;

HashTable *create_hash_table(void);
void delete_hash_table(HashTable *hashtable);

bool hash_insert(HashTable *table, Movie *movie);
Movie *hash_search(HashTable *table, char *movie_name);
void hash_print(HashTable *table);

#endif
