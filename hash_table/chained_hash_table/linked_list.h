#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "table_item.h"

#include <stdbool.h>

typedef struct Node {
    Item *item;
    struct Node *next;
} Node;

Node *create_node(const Item *item);
void delete_node(Node *node);
void print_node(const Node *node);

/**
 * @return
 * Returns true if any new node has been pushed.
 * Returns false when no new node has been pushed,
 * includes malloc failure and replacing same key.
*/
bool insert_node(Node **headptr, const Item *item);
bool remove_node(Node **headptr, const keytype key);

void print_list(const Node *node);
/**
 * @return
 * Returns the number of nodes deleted from the stack.
*/
int delete_list(Node *node);

#endif
