#pragma once

typedef struct Node {
    int value;
    struct Node *left, *right;
    struct Node *parent;
} Node;

Node *create_tree(const int *array, int length);
void delete_tree(Node *root);
void print_inorder(const Node *root);
int get_height(const Node *root);
