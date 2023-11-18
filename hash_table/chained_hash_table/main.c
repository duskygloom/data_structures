#include "hash_table.h"

int main()
{
    Movie *movie_list[NUM_MOVIES];

    // filling movie list from file
    FILE *moviefile = fopen(MOVIE_FILE, "r");
    skip_until(moviefile, '\n');                            // skip first line
    for (int i = 0; i < NUM_MOVIES; ++i) {
        movie_list[i] = get_movie_from_file(moviefile);
        // print_movie(movie_list[i]);
    }
    fclose(moviefile);

    // creating hash table from movie list
    Node **hash_table = calloc(TABLE_SIZE, sizeof(Node *));
    for (int i = 0; i < NUM_MOVIES; ++i) {
        hash_insert(hash_table, create_node(movie_list[i]));
    }
    // hash_print(hash_table);
    // putchar('\n');

    // searching movie
    printf("Movie name: ");
    char movie_name[MOVIE_NAME_LENGTH+1];
    get_string(movie_name, MOVIE_NAME_LENGTH);
    printf("%s: %d\n", movie_name, hash_function(movie_name));
    Movie *result = hash_search(hash_table, movie_name);
    if (result) print_movie(result);
    else printf("Could not find: %s\n", movie_name);

    // freeing memory
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete_list(hash_table[i]);
    }
    free(hash_table);
    for (int i = 0; i < NUM_MOVIES; ++i)
        delete_movie(movie_list[i]);

    return 0;
}
