#ifndef MOVIE_H
#define MOVIE_H

#include <stdlib.h>
#include <stdio.h>

#define MOVIE_NAME_LENGTH   79

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

static inline void skip_until(FILE *file, int ch)
{
    while (fgetc(file) != ch || feof(file));
}

Movie *get_movie_from_file(FILE *moviefile);

#endif
