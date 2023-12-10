#include "hashtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashfunction(const keytype key)
{
    int hash = 0;
    for (int i = 0; *(key+i); ++i)
        hash = 2*hash + *(key+i);
    return hash;
}

HashTable *create_hashtable(int maxsize)
{
    HashTable *hashtable = malloc(sizeof(HashTable));
    hashtable->maxsize = maxsize;
    hashtable->length = 0;
    hashtable->items = calloc(maxsize, sizeof(Item *));
    return hashtable;
}

void delete_hashtable(HashTable *hashtable)
{
    if (hashtable == NULL) return;
    if (hashtable->items == NULL) {
        free(hashtable);
        return;
    }
    for (int i = 0; i < hashtable->maxsize; ++i)
        if (hashtable->items[i]) {
            delete_item(hashtable->items[i]);
            hashtable->items[i] = NULL;
            --(hashtable->length);
        }
    free(hashtable->items);
    free(hashtable);
}

void print_hashtable(const HashTable *hashtable)
{
    for (int i = 0; i < hashtable->maxsize; ++i) {
        printf("%d: ", i);
        print_item(hashtable->items[i]);
    }
}

/**
 * @note
 * Copies item to hashtable so it is
 * fine to free the original item.
*/
bool hash_insert(HashTable *hashtable, const Item *item)
{
    int hash = hashfunction(item->key) % hashtable->maxsize;
    int i = 0, offset, index;
    Item *curr;
    for (; i < hashtable->maxsize; ++i) {
        offset = i * i;
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        if (curr == NULL) break;                                        // found!
        else if (strcmp(curr->key, item->key) == 0) {                   // replace same key
            curr->value = item->value;
            return true;
        }
    }
    if (i >= hashtable->maxsize) return false;                          // fully scanned
    // actutal insertion
    Item *newitem = create_item(item->key, item->value);
    if (newitem == NULL) return false;
    hashtable->items[index] = newitem;
    ++(hashtable->length);
    return true;
}

bool hash_delete(HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    int index, offset, i = 0;
    Item *curr;
    for (; i < hashtable->maxsize; ++i) {
        offset = i * i;
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        if (curr && strcmp(curr->key, key) == 0) break;                 // found!
    }
    if (i >= hashtable->maxsize) return false;                          // fully scanned
    // actual deletion
    delete_item(curr);
    hashtable->items[index] = NULL;
    --(hashtable->length);
    return true;
}

Item *hash_search(const HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    int index, offset, i = 0;
    Item *curr;
    for (; i < hashtable->maxsize; ++i) {
        offset = i * i;
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        if (curr && strcmp(curr->key, key) == 0) break;                 // found!
    }
    if (i >= hashtable->maxsize) return NULL;                           // fully scanned
    // actual search result
    return curr;
}
