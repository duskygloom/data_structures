#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void delete_node(Node *node)
{
    if (node) free(node);
}

void prepend(Node **headptr, int value)
{
    Node *newhead = create_node(value);
    newhead->next = *headptr;
    *headptr = newhead;
}

int pop_head(Node **headptr)
{
    if (!*headptr) return -1;
    Node *next = (*headptr)->next;
    int value = (*headptr)->value;
    free(*headptr);
    *headptr = next;
    return value;
}

void print_list(Node *head)
{
    putchar('[');
    if (head) {
        printf("%d", head->value);
        head = head->next;
    }
    while (head) {
        printf(", %d", head->value);
        head = head->next;
    }
    printf("]\n");
}

void delete_list(Node **headptr)
{
    Node *curr = *headptr, *next = NULL;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *headptr = NULL;
}
