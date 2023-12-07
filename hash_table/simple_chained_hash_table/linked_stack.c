#include "linked_stack.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(const Item *item)
{
    Node *node = malloc(sizeof(Node));
    node->item = create_item(item->key, item->value);
    node->next = NULL;
    return node;
}

void delete_node(Node *node)
{
    if (node) {
        if (node->item) free(node->item);
        free(node);
    }
}

void print_node(const Node *node)
{
    if (node == NULL) printf("---\n");
    else print_item(node->item);
}

bool list_push(Node *head, const Item *item)
{
    Node *newnode = create_node(item);
    if (newnode == NULL) return false;
    newnode->next = head;
    head = newnode;
    return true; 
}

bool list_pop(Node *head)
{
    if (head == NULL) return false;
    Node *secondnode = head->next;
    free(head);
    head = secondnode;
}
