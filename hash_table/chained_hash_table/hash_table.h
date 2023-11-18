#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE          256
#define NUM_MOVIES          250
#define MOVIE_NAME_LENGTH   79
#define MOVIE_FILE          "top_english_movies.csv"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Movie {
    char *name;
    int year;
} Movie;

Movie *create_movie(char *name, int year);

static inline void delete_movie(Movie *movie)
{
    free(movie->name);
    free(movie);
}

static inline void print_movie(Movie *movie)
{
    printf("%s - %d\n", movie->name, movie->year);
}

typedef struct Node {
    Movie *movie;
    struct Node *next;
} Node;

Node *create_node(Movie *movie);

static inline void delete_node(Node *node)
{
    // delete_movie(node->movie);
    free(node);
}

static inline void print_node(Node *node)
{
    printf("(%p) -> %p: ", node, node->next);
    print_movie(node->movie);
}

bool insert_node(Node *head, Node *node);
bool delete_list(Node *head);

uint8_t hash_function(char *key);

static inline void skip_until(FILE *file, int ch)
{
    while (fgetc(file) != ch || feof(file));
}

Movie *get_movie_from_file(FILE *moviefile);

bool hash_insert(Node **table, Node *node);
Movie *hash_search(Node **table, char *movie_name);
void hash_print(Node **table);

int get_string(char *buffer, int length);

#endif
