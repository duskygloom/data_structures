#include "hash_table.h"
#include "linked_list.h"

int get_string(char *buffer, int length);

int main()
{
    Movie *movielist[NUM_MOVIES];

    // filling movie list from file
    FILE *moviefile = fopen(MOVIE_FILE, "r");
    skip_until(moviefile, '\n');                            // skip first line
    for (int i = 0; i < NUM_MOVIES; ++i) {
        movielist[i] = get_movie_from_file(moviefile);
        // print_movie(movielist[i]);
    }
    fclose(moviefile);

    // creating hash table from movie list
    HashTable *hashtable = create_hashtable();
    for (int i = 0; i < NUM_MOVIES; ++i)
        hash_insert(hashtable, movielist[i]);
    #ifdef DEBUG_MODE
    check_collision(true);
    putchar('\n');
    print_hashtable(hashtable);
    putchar('\n');
    #endif

    // searching movie
    printf("Movie name: ");
    char moviename[MOVIE_NAME_LENGTH+1];
    get_string(moviename, MOVIE_NAME_LENGTH);
    printf("%s: %d\n", moviename, hash_function(moviename));
    Movie *result = hash_search(hashtable, moviename);
    if (result) print_movie(result);
    else printf("Could not find: %s\n", moviename);

    // freeing memory
    delete_hashtable(hashtable);
    for (int i = 0; i < NUM_MOVIES; ++i)
        delete_movie(movielist[i]);

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
