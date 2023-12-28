#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(const Item *item)
{
    if (!item) return NULL;
    Node *node = malloc(sizeof(Node));
    node->item = create_item(item->key, item->value);
    return node;
}

void delete_node(Node *node)
{
    if (!node) return;
    if (node->item) free(node->item);
    free(node);
}

void print_node(const Node *node)
{
    if (node && node->item) {
        print_item(node->item);
        
    }
}
