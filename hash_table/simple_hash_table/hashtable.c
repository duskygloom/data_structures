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

/**
 * @note
 * Copies key and value to item so it is 
 * fine to free the original key and value
*/
Item *create_item(keytype key, valuetype value)
{
    Item *item = malloc(sizeof(Item));
    item->key = calloc(strlen(key)+1, sizeof(char));
    strcpy(item->key, key);
    item->value = value;
    return item;
}

void delete_item(Item *item)
{
    if (item) {
        if (item->key) free(item->key);
        free(item);
    }
}

void print_item(const Item *item)
{
    if (item) printf("%s - %d\n", item->key, item->value);
    else printf("---\n");
}

HashTable *create_hashtable(int maxsize)
{
    HashTable *hashtable = malloc(sizeof(HashTable));
    hashtable->maxsize = maxsize;
    hashtable->length = 0;
    hashtable->nodes = calloc(maxsize, sizeof(Item *));
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
            delete_item(hashtable->nodes[i]);
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
bool hash_insert(HashTable *hashtable, Item *item)
{
    int hash = hashfunction(item->key) % hashtable->maxsize;
    Item *tableitem = hashtable->nodes[hash];
    if (tableitem && strcmp(tableitem->key, item->key) == 0) {
        tableitem->value = item->value;
        return true;
    }
    else if (tableitem) {
        delete_item(tableitem);
        --(hashtable->length);
    }
    hashtable->nodes[hash] = create_item(item->key, item->value);
    ++(hashtable->length);
    return true;
}

bool hash_delete(HashTable *hashtable, keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    Item *item = hashtable->nodes[hash];
    if (item && strcmp(item->key, key) == 0) {
        delete_item(item);
        hashtable->nodes[hash] = NULL;
        --(hashtable->length);
        return true;
    }
    return false;
}

Item *hash_search(const HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    return hashtable->nodes[hash];
}
