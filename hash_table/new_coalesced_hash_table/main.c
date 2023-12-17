#include "hashtable.h"

#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 11
#define NUM_ITEMS       7

int main()
{
    HashTable *hashtable = create_hashtable(HASH_TABLE_SIZE);
    putchar('\n');
    print_hashtable(hashtable);
    Item **items = calloc(NUM_ITEMS, sizeof(Item *));
    items[0] = create_item("const", 5);
    items[1] = create_item("sizeof", 6);
    items[2] = create_item("for", 3);
    items[3] = create_item("while", 5);
    items[4] = create_item("if", 2);
    items[5] = create_item("return", 6);
    items[6] = create_item("typedef", 7);
    for (int i = 0; i < NUM_ITEMS; ++i) {
        hash_insert(hashtable, items[i]);
        delete_item(items[i]);
    }
    free(items);
    putchar('\n');
    print_hashtable(hashtable);
    print_item(hash_search(hashtable, "break"));
    print_item(hash_search(hashtable, "const"));
    print_item(hash_search(hashtable, "return"));
    hash_delete(hashtable, "break");
    hash_delete(hashtable, "sizeof");
    // hash_delete(hashtable, "return");
    putchar('\n');
    print_hashtable(hashtable);
    print_item(hash_search(hashtable, "break"));
    print_item(hash_search(hashtable, "const"));
    print_item(hash_search(hashtable, "return"));
    delete_hashtable(hashtable);
    return 0;
}
