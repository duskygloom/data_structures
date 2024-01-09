#ifndef BST_H
#define BST_H

#include "tree.h"

Node *bst_insert(Node *root, int value);
Node *bst_delete(Node *root, int value);
Node *bst_search(Node *root, int value);

#endif

