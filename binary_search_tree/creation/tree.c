#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_tree(const Node *root, int spaces) {
    if (root->right) print_tree(root->right, spaces+1);
    for (int i = 0; i < spaces; ++i) putchar('\t');
    printf("%d\n", root->value);
    if (root->left) print_tree(root->left, spaces+1);
}

void delete_tree(Node *root) {
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}
