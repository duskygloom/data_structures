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
        print_node(hashtable->nodes[i]);
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
    /**
     * @note
     * Find bucket of the last node.
     * Bucket is the pointer to the node.
     * Bucket is needed to make changes into the node
     * and to find the hash using pointer arithmetic.
    */
    Node **bucket = hashtable->nodes + hash;
    while (*bucket) {
        if ((*bucket)->next == NULL) break;                             // found last node!
        else if (strcmp((*bucket)->item->key, item->key) == 0) {        // replace same key
            (*bucket)->item->value = item->value;
            return true;
        }
        bucket = &((*bucket)->next);
    }
    // int offset = 0;
    // int maxoffset = hashtable->maxsize - (bucket - hashtable->nodes);
    // for (; offset < maxoffset; ++offset) {
    //     if (*(bucket+offset) == NULL) break;                                // found!
    //     else if (strcmp((*(bucket+offset))->item->key, item->key) == 0) {   // replace same key
    //         (*(bucket+offset))->item->value = item->value;
    //         return true;
    //     }
    // }
    // find offset from last linked node to hash
    int lastnode = bucket - hashtable->nodes, index, offset = 0;
    Node *curr;
    for (; offset < hashtable->maxsize; ++offset) {
        index = (lastnode + offset) % hashtable->maxsize;
        curr = hashtable->nodes[index];
        if (curr == NULL) break;                                        // found!
        else if (strcmp(curr->item->key, item->key) == 0) {             // replace same key
            curr->item->value = item->value;
            return true;
        }
    }
    // insert at index
    Node *newnode = create_node(item);
    if (newnode == NULL) return false;
    // *(bucket+offset) = newnode;
    // if (bucket != bucket+offset) (*bucket)->next = newnode;
    hashtable->nodes[index] = newnode;
    if (offset != 0) hashtable->nodes[lastnode]->next = newnode;
    ++(hashtable->length);
    return true;
}

bool hash_delete(HashTable *hashtable, const keytype key)
{
    int hash = hashfunction(key) % hashtable->maxsize;
    if (remove_node(hashtable->nodes+hash, key)) {
        --(hashtable->length);
        return true;
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
