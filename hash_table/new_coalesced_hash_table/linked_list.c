#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *create_node(const Item *item)
{
    Node *node = malloc(sizeof(Node));
    node->item = create_item(item->key, item->value);
    node->nextbucket = NULL;
    return node;
}

void delete_node(Node *node)
{
    if (node) {
        if (node->item) {
            delete_item(node->item);
            node->item = NULL;
        }
        free(node);
    }
}

void print_node(const Node *node)
{
    if (node == NULL) printf("---\n");
    else printf("(%s, %d)\n", node->item->key, node->item->value);
}

bool remove_node(Node **headptr, const keytype key)
{
    Node *prev = NULL, *curr = *headptr;
    while (curr) {
        if (strcmp(curr->item->key, key) == 0) break;                       // found!
        prev = curr;
        curr = *(curr->nextbucket);
    }
    if (curr == NULL) return false;                                         // not found
    if (prev) *(prev->nextbucket) = *(curr->nextbucket);
    else *headptr = curr->next;
    delete_node(curr);
    return true;
}

void print_list(const Node *node)
{
    if (node == NULL) {
        printf("---\n");
        return;
    }
    printf("(%s, %d)", node->item->key, node->item->value);
    if (node->next) {
        node = node->next;
        printf(" -> (%s, %d)", node->item->key, node->item->value);
    }
    putchar('\n');
}

int delete_list(Node *node)
{
    int node_counter = 0;
    Node *next;
    while (node) {
        next = node->next;
        delete_node(node);
        node = next;
        ++node_counter;
    }
    return node_counter;
}
