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

void print_stack(const Node *node);
void delete_stack(Node *node);

#endif
