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

void append(Node **headptr, Node **tailptr, int value)
{
    Node *newtail = create_node(value);
    newtail->next = *headptr;
    if (!*headptr && !*tailptr) {
        newtail->next = newtail;
        *headptr = *tailptr = newtail;
        return;
    }
    Node *tail = *tailptr;
    tail->next = newtail;
    *tailptr = newtail;
}

int pop_head(Node **headptr, Node **tailptr)
{
    // If no elements
    Node *head = *headptr;
    if (!head) return -1;
    // If only 1 element
    int value = head->value;
    if (head == *tailptr) {
        delete_node(head);
        *headptr = *tailptr = NULL;
        return value;
    }
    // If more than 1 elements
    Node *next = head->next;
    delete_node(head);
    (*tailptr)->next = *headptr = next;
    return value;
}

void print_list(Node *head)
{
    Node *curr = head;
    putchar('[');
    if (curr) {
        printf("%d", curr->value);
        curr = curr->next;
    }
    while (curr != head) {
        printf(", %d", curr->value);
        curr = curr->next;
    }
    if (curr) printf(" -> %d", curr->value);
    printf("]\n");
}

void delete_list(Node **headptr, Node **tailptr)
{
    Node *curr = *headptr, *next = NULL;
    while (curr != *headptr) {
        next = curr->next;
        delete_node(curr);
        curr = next;
    }
    *headptr = *tailptr = NULL;
}
