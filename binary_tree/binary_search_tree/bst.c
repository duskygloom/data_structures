#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void insert(Node *root, int value) {
    if (value < root->value && root->left) insert(root->left, value);
    else if (value >= root->value && root->right) insert(root->right, value);
    else if (value < root->value) root->left = create_node(value);
    else root->right = create_node(value);
}

void insert_node(Node *root, Node *node) {
    if (!node) return;
    if (node->value < root->value && root->left) insert_node(root->left, node);
    else if (node->value >= root->value && root->right) insert_node(root->right, node);
    else if (node->value < root->value) root->left = node;
    else root->right = node;
}

void remove_node(Node *root, Node *prev, int value) {
    if (prev)
        printf("root: %x %d, prev: %x %d, value: %d\n", root, root->value, prev, prev->value, value);
    else
        printf("root: %x %d, prev: %x %d, value: %d\n", root, root->value, prev, 0, value);

    if (prev && root && root->value == value) {
        Node *left = root->left;
        Node *right = root->right;

        if (left && right) {
            if (prev->left && prev->left->value == value) prev->left = left;
            else prev->right = left;
            insert_node(root->left, root->right);
        }
        
        else if (left) {
            if (prev->left && prev->left->value == value) prev->left = left;
            else prev->right = left;
        }
        
        else if (right) {
            if (prev->left && prev->left->value == value) prev->left = right;
            else prev->right = right;
        }

        free(root);
        root = prev;
    }
    if (root && root->left) remove_node(root->left, root, value);
    if (root && root->right) remove_node(root->right, root, value);
}
