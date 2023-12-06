#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE          389
#define NUM_MOVIES          250
#define MOVIE_FILE          "top_english_movies.csv"
#define LOAD_FACTOR         0.65

// #define DEBUG_MODE

#include "movie.h"
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;
uint hash_function(char *key);

void check_collision(bool print_collision);

typedef struct HashTable {
    int length;
    Node **table;
} HashTable;

HashTable *create_hashtable();
void delete_hashtable(HashTable *hashtable);
void print_hashtable(HashTable *hashtable);

bool hash_insert(HashTable *hashtable, Movie *movie);
Movie *hash_search(HashTable *hashtable, char *moviename);
void hash_print(HashTable *hashtable);

#endif
