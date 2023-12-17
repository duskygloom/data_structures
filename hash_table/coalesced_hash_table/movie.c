#include "movie.h"

#include <string.h>

Movie *create_movie(char *name, int year)
{
    Movie *movie = malloc(sizeof(Movie));
    movie->name = strdup(name);
    movie->year = year;
    return movie;
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
