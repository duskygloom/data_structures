#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "table_item.h"
#include "linked_list.h"

#include <stdbool.h>

int hashfunction(const keytype key);

typedef struct HashTable {
    int maxsize;
    int length;
    Node **lists;
} HashTable;

HashTable *create_hashtable(int maxsize);
void delete_hashtable(HashTable *hashtable);
void print_hashtable(const HashTable *hashtable);

/**
 * @note
 * Copies item to hashtable so it is
 * fine to free the original item.
 * @return
 * Returns true if any new node has been pushed.
 * Returns false when no new node has been pushed,
 * includes malloc failure and replacing same key.
*/
bool hash_insert(HashTable *hashtable, const Item *item);
bool hash_delete(HashTable *hashtable, const keytype key);
Item *hash_search(const HashTable *hashtable, const keytype key);

#endif
