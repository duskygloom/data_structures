#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "table_item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    Item *item;
    struct Node *next;
} Node;

Node *create_node(Item *item);

static inline void delete_node(Node *node)
{
    // delete_movie(node->movie);
    free(node);
}

static inline void print_node(Node *node)
{
    printf("(%p) -> %p: ", node, node->next);
    print_movie(node->movie);
}

bool insert_node(Node *head, Node *node);
bool delete_list(Node *head);

#endif
