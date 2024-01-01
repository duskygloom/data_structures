#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value);

void print_tree(const Node *root, int tabs);
void delete_tree(Node *root);

#endif
