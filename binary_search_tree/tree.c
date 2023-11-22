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

void print_inorder(const Node *root) {
    if (root->left) print_inorder(root->left);
    printf(" %d", root->value);
    if (root->right) print_inorder(root->right);
}

void print_reverse_inorder(const Node *root) {
    if (root->right) print_reverse_inorder(root->right);
    printf(" %d", root->value);
    if (root->left) print_reverse_inorder(root->left);
}

void print_preorder(const Node *root) {
    printf(" %d", root->value);
    if (root->left) print_preorder(root->left);
    if (root->right) print_preorder(root->right);
}

void print_postorder(const Node *root) {
    if (root->left) print_postorder(root->left);
    if (root->right) print_postorder(root->right);
    printf(" %d", root->value);
}