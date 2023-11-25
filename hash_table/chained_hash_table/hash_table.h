#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE          389
#define NUM_MOVIES          250
#define MOVIE_FILE          "top_english_movies.csv"
#define LOAD_FACTOR         0.65

#include "movie.h"
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;
uint hash_function(char *key);

void check_collision(bool print_collision);

bool hash_insert(Node **table, Node *node);
Movie *hash_search(Node **table, char *movie_name);
void hash_print(Node **table);

#endif