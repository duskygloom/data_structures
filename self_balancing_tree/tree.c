#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value, const Node *parent)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    node->parent = parent;
    return node;
}

void bst_insert(Node *root, int value)
{
    if (value < root->value && root->left == NULL)
        root->left = create_node(value, root);
    else if (value < root->value)
        bst_insert(root->left, value);
    else if (root->right == NULL)
        root->right = create_node(value, root);
    else bst_insert(root->right, value);
}

Node *create_tree(const int *array, int length)
{
    Node *root = create_node(array[0], NULL);
    for (int i = 1; i < length; ++i)
        bst_insert(root, array[i]);
    return root;
}

void delete_tree(Node *root)
{
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

void _print_inorder(const Node *root)
{
    if (root->left) _print_inorder(root->left);
    printf("%d, ", root->value);
    if (root->right) _print_inorder(root->right);
}

void print_inorder(const Node *root)
{
    if (root == NULL) printf("[]\n");
    else {
        printf("[");
        _print_inorder(root);
        printf("\b\b]\n");
    }
}

int get_height(const Node *root)
{
    if (root == NULL) return 0;
    else if (get_height(root->left) < get_height(root->right))
        return 1 + get_height(root->right);
    return 1 + get_height(root->left);
}

Node *_ll_rotation(Node *node)
{
    node->left->right = node;
    return node->left;
}

Node *_rr_rotation(Node *node)
{
    node->right->left = node;
    return node->right;
}

Node *_lr_rotation(Node *node)
{
    node->left->right->left = node->left;
    node->left->right->right = node;
    return node->left->right;
}

Node *_rl_rotation(Node *node)
{
    node->right->left->left = node;
    node->right->left->right = node->right;
    return node->right->left;
}

void balance_node(Node *root)
{
    if (!(root && root->parent && root->parent->parent))
        return;
    
}

Node *avl_insert(Node *root, int value)
{
    if (root == NULL) return NULL;
    else if (value < root->value && root->left == NULL)
        root->left = create_node(value, root);
    else if (value < root->value)
        avl_insert(root->left, value);
    else if (root->right == NULL)
        root->right = create_node(value, root);
    avl_insert(root->right, value);
}
