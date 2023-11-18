#include "hash_table.h"

#include <ctype.h>
#include <string.h>

Movie *create_movie(char *name, int year)
{
    Movie *movie = malloc(sizeof(Movie));
    movie->name = strdup(name);
    movie->year = year;
    return movie;
}

Node *create_node(Movie *movie)
{
    Node *node = malloc(sizeof(Node));
    node->movie = movie;
    node->next = NULL;
    return node;
}

bool insert_node(Node *head, Node *node)
{
    while (head->next != NULL) {
        if (node->movie->name == head->movie->name)
            return false;                                   // no override
        head = head->next;
    }
    head->next = node;
    return true;
}

bool delete_list(Node *head)
{
    Node *next;
    while (head) {
        next = head->next;
        delete_node(head);
        head = next;
    }
}

uint8_t hash_function(char *key)
{
    uint8_t hash = 0;
    while (*key) {
        hash = (hash >> 1) | ((hash & 1) << 7);
        hash += tolower(*key++);                        // for case insensitive hashes
        hash &= UINT8_MAX;
    }
    return hash;
}

Movie *get_movie_from_file(FILE *moviefile)
{
    skip_until(moviefile, ',');                         // skip first record
    char movie_name[MOVIE_NAME_LENGTH+1];
    int ch, index = 0, year;
    while ((ch = fgetc(moviefile)) != ',' && index < MOVIE_NAME_LENGTH) {
        if (ch == '"') {
            while ((ch = fgetc(moviefile)) != '"' && index < MOVIE_NAME_LENGTH)
                movie_name[index++] = ch;
            break;
        }
        movie_name[index++] = ch;
    }
    movie_name[index] = '\0';
    fscanf(moviefile, "%d", &year);
    skip_until(moviefile, '\n');                            // go to next line
    Movie *movie = create_movie(movie_name, year);
    return movie;
}

bool hash_insert(Node **table, Node *node)
{
    uint8_t index = hash_function(node->movie->name);
    if (!table[index]) {
        table[index] = node;
        return true;
    }
    return insert_node(table[index], node);
}

#ifndef __cplusplus__strings__
// case insensitive string comparison
int stricmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && tolower(*str1++) == tolower(*str2++));
    return *str1 - *str2;
}
#endif

Movie *hash_search(Node **table, char *movie_name)
{
    uint8_t index = hash_function(movie_name);
    Node *curr = table[index];
    while (curr) {
        if (stricmp(curr->movie->name, movie_name) == 0)
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

int get_string(char *buffer, int length)
{
    int ch, counter = 0;
    while ((ch = getchar()) != '\n' && counter < length)
        buffer[counter++] = ch;
    buffer[counter] = '\0';
    return counter;
}
