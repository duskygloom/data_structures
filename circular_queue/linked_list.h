#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_node(int value);
void delete_node(Node *node);

void append(Node **headptr, Node **tailptr, int value);
int pop_head(Node **headptr, Node **tailptr);
void print_list(Node *head);

void delete_list(Node **headptr, Node **tailptr);

#endif
