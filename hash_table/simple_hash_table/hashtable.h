#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef char * keytype;
typedef int valuetype;

int hashfunction(const keytype key);

typedef struct Item {
    keytype key;
    valuetype value;
} Item;

Item *create_item(keytype key, valuetype value);
void delete_item(Item *item);
void print_item(const Item *item);

typedef struct HashTable {
    int maxsize;
    int length;
    Item **items;
} HashTable;

HashTable *create_hashtable(int maxsize);
void delete_hashtable(HashTable *hashtable);
void print_hashtable(const HashTable *hashtable);

bool hash_insert(HashTable *hashtable, Item *item);
bool hash_delete(HashTable *hashtable, keytype key);
Item *hash_search(const HashTable *hashtable, const keytype key);

#endif
