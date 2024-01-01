#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void insert(Node *root, int value) {
    if (value < root->value && root->left) insert(root->left, value);
    else if (value >= root->value && root->right) insert(root->right, value);
    else if (value < root->value) root->left = create_node(value);
    else root->right = create_node(value);
}
