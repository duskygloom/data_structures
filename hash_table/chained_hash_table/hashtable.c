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
    hashtable->lists = calloc(maxsize, sizeof(Node *));
    return hashtable;
}

void delete_hashtable(HashTable *hashtable)
{
    if (hashtable == NULL) return;
    if (hashtable->lists == NULL) {
        free(hashtable);
        return;
    }
    for (int i = 0; i < hashtable->maxsize; ++i)
        if (hashtable->lists[i]) {
            int node_counter = delete_list(hashtable->lists[i]);
            hashtable->lists[i] = NULL;
            hashtable->length -= node_counter;
        }
    free(hashtable->lists);
    free(hashtable);
}

void print_hashtable(const HashTable *hashtable)
{
    for (int i = 0; i < hashtable->maxsize; ++i) {
        printf("%d: ", i);
        print_list(hashtable->lists[i]);
    }
}

bool hash_insert(HashTable *hashtable, const Item *item)
{
    int hash = hashfunction(item->key) % hashtable->maxsize;
    Node *node = hashtable->lists[hash];
    if (insert_node(hashtable->lists+hash, item)) {
        ++(hashtable->length);
        return true;
    }
    return false;
}

bool hash_delete(HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    Node *node = hashtable->lists[hash], *prev = NULL;
    if (remove_node(hashtable->lists+hash, key)) {
        --(hashtable->length);
        return true;
    }
    return false;
}

Item *hash_search(const HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    Node *node = hashtable->lists[hash];
    if (node == NULL) return NULL;
    while (node) {
        if (strcmp(node->item->key, key) == 0)
            return node->item;
        node = node->next;
    }
    return NULL;
}
