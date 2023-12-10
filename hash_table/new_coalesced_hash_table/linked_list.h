#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "table_item.h"

#include <stdbool.h>

typedef struct Node {
    Item *item;
    struct Node **nextbucket;
} Node;

Node *create_node(const Item *item);
void delete_node(Node *node);
void print_node(const Node *node);

bool remove_node(Node **headptr, const keytype key);

void print_list(const Node *node);
/**
 * @return
 * Returns the number of nodes deleted from the stack.
*/
int delete_list(Node *node);

#endif
