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
        if (node->item) delete_item(node->item);
        free(node);
    }
}

void print_node(const Node *node)
{
    if (node == NULL) printf("---\n");
    else printf("(%s, %d)\n", node->item->key, node->item->value);
}

bool push_node(Node *head, const Item *item)
{
    Node *newnode = create_node(item);
    if (newnode == NULL) return false;
    newnode->next = head;
    head = newnode;
    return true; 
}

bool pop_node(Node *head)
{
    if (head == NULL) return false;
    Node *secondnode = head->next;
    free(head);
    head = secondnode;
}

void print_stack(const Node *node)
{
    if (node == NULL) {
        printf("---\n");
        return;
    }
    printf("(%s, %d)", node->item->key, node->item->value);
    while (node->next) {
        node = node->next;
        printf(" -> (%s, %d)", node->item->key, node->item->value);
    }
    putchar('\n');
}

void delete_stack(Node *node)
{
    Node *prev;
    while (node) {
        prev = node;
        node = node->next;
        free(prev);
    }
}
