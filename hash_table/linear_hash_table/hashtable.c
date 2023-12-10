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
    int index, offset = 0;
    Item *curr;
    // finds an empty bucket index
    for (; offset < hashtable->maxsize; ++offset) {
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        if (curr == NULL) break;
        // replace if same key
        else if (strcmp(curr->key, item->key) == 0) {
            curr->value = item->value;
            return true;
        }
    }
    if (curr) return false;                                             // no empty bucket
    // actual insertion
    Item *newitem = create_item(item->key, item->value);
    if (newitem == NULL) return false;
    hashtable->items[index] = newitem;
    ++(hashtable->length);
    return true;
}

bool hash_delete(HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    int index, offset = 0;
    Item *curr;
    // finds index of the key
    for (; offset < hashtable->maxsize; ++offset) {
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        /**
         * @note
         * Since this is linear probing, checking the entire table is
         * not necessary. If one NULL is found, it means that the key
         * does not exist.
        */
        if (curr == NULL) return false;
        else if (strcmp(curr->key, key) == 0) break;                    // found!
    }
    if (offset >= hashtable->maxsize) return false;                     // fully scanned
    // actual deletion
    delete_item(curr);
    hashtable->items[index] = NULL;
    --(hashtable->length);
    return true;
}

Item *hash_search(const HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    int index, offset = 0;
    Item *curr;
    // finds index of the key
    for (; offset < hashtable->maxsize; ++offset) {
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->items[index];
        if (curr == NULL) return false;                                 // not found
        else if (strcmp(curr->key, key) == 0) break;                    // found!
    }
    if (offset >= hashtable->maxsize) return NULL;                      // fully scanned
    return hashtable->items[index];
}
