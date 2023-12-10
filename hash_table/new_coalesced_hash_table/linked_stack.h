#ifndef LINKED_STACK_H
#define LINKED_STACK_H

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
 * Returns pointer to the inserted node.
 * Returns NULL if no new node has been inserted,
 * it includes value overwrite and malloc failures.
*/
Node *insert_node(Node **headptr, const Item *item);
bool remove_node(Node **headptr, const keytype key);

void print_stack(const Node *node);
/**
 * @return
 * Returns the number of nodes deleted from the stack.
*/
int delete_stack(Node *node);

#endif
