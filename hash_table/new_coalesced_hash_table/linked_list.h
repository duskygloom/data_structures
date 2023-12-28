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

Node *insert_node(Node *list, const Item *item);
bool remove_node(Node *list, const keytype key);

/**
 * @return
 * The head node contains no value.
 * It only contains the pointer to head.
*/
Node *create_list();
void print_list(const Node *node);
/**
 * @return
 * Returns the number of nodes deleted from the stack.
*/
int delete_list(Node *node);

#endif
