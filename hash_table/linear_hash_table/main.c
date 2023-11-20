#include "hash_table.h"

int get_string(char *buffer, int length);

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
    HashTable *hash_table = create_hash_table();
    for (int i = 0; i < NUM_MOVIES; ++i) {
        if (!hash_insert(hash_table, movie_list[i])) {
            printf("Could not insert: ");
            print_movie(movie_list[i]);
        }
    }
    check_collision(true);
    putchar('\n');
    // hash_print(hash_table);
    // putchar('\n');

    // searching movie
    printf("Movie name: ");
    char movie_name[MOVIE_NAME_LENGTH+1];
    get_string(movie_name, MOVIE_NAME_LENGTH);
    int result = hash_search(hash_table, movie_name);
    printf("%s: %d(%d)\n", movie_name, result, hash_function(movie_name));
    if (result == -1) printf("Could not find: %s\n", movie_name);
    else print_movie(hash_table->array[result]);

    // freeing memory
    free(hash_table);
    for (int i = 0; i < NUM_MOVIES; ++i)
        delete_movie(movie_list[i]);

    return 0;
}

int get_string(char *buffer, int length)
{
    int ch, counter = 0;
    while ((ch = getchar()) != '\n' && counter < length)
        buffer[counter++] = ch;
    buffer[counter] = '\0';
    return counter;
}
