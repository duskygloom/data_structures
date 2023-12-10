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
    hashtable->nodes = calloc(maxsize, sizeof(Node *));
    return hashtable;
}

void delete_hashtable(HashTable *hashtable)
{
    if (hashtable == NULL) return;
    if (hashtable->nodes == NULL) {
        free(hashtable);
        return;
    }
    for (int i = 0; i < hashtable->maxsize; ++i)
        if (hashtable->nodes[i]) {
            delete_node(hashtable->nodes[i]);
            hashtable->nodes[i] = NULL;
            --(hashtable->length);
        }
    free(hashtable->nodes);
    free(hashtable);
}

void print_hashtable(const HashTable *hashtable)
{
    for (int i = 0; i < hashtable->maxsize; ++i) {
        printf("%d: ", i);
        print_item(hashtable->nodes[i]);
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
    Node *curr;
    // finds an empty bucket index
    for (; offset < hashtable->maxsize; ++offset) {
        index = (hash + offset) % hashtable->maxsize;
        curr = hashtable->nodes[index];
        if (curr == NULL) break;
        else if (strcmp(curr->item->key, item->key) == 0) {             // replace same key
            curr->item->value = item->value;
            return true;
        }
    }
    if (curr) return false;                                             // no empty bucket
    // actual insertion
    Node *newnode = create_node(item);
    if (newnode == NULL) return false;
    hashtable->nodes[index] = newnode;
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
        curr = hashtable->nodes[index];
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
    hashtable->nodes[index] = NULL;
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
        curr = hashtable->nodes[index];
        if (curr == NULL) return false;                                 // not found
        else if (strcmp(curr->key, key) == 0) break;                    // found!
    }
    if (offset >= hashtable->maxsize) return NULL;                      // fully scanned
    return hashtable->nodes[index];
}
