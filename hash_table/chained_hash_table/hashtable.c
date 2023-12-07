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
            delete_stack(hashtable->nodes[i]);
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
        print_stack(hashtable->nodes[i]);
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
    Node *node = hashtable->nodes[hash];
    if (node == NULL) {
        hashtable->nodes[hash] = create_node(item);
        if (hashtable->nodes[hash]) {
            ++(hashtable->length);
            return true;
        }
        return false;
    }
    while (node->next) {
        if (strcmp(node->item->key, item->key) == 0) {
            node->item->value = item->value;
            return true;
        }
        node = node->next;
    }
    node->next = create_node(item);
    if (node->next) return true;
    return false;
}

bool hash_delete(HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    Node *node = hashtable->nodes[hash], *prev = NULL;
    if (node == NULL) return false;
    while (node) {
        if (strcmp(node->item->key, key) == 0) {
            if (prev) prev->next = node->next;
            else hashtable->nodes[hash] = node->next;
            free(node);
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

Item *hash_search(const HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    Node *node = hashtable->nodes[hash];
    if (node == NULL) return NULL;
    while (node) {
        if (strcmp(node->item->key, key) == 0)
            return node->item;
        node = node->next;
    }
    return NULL;
}
