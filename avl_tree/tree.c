#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value)
{
	Node *node = malloc(sizeof(Node));
	if (!node) return NULL;
	node->value = value;
	node->right = node->left = NULL;
	node->height = 1;
	return node;
}

Node *delete_node(Node *node)
{
	if (node) free(node);
	return NULL;
}

Node *delete_tree(Node *root)
{
	if (!root) return NULL;
	root->left = delete_tree(root->left);
	root->right = delete_tree(root->right);
	root = delete_node(root);
	return root;
}

int update_height(Node *root)
{
	if (!root) return 0;
	return root->height = 
		MAX(update_height(root->left), update_height(root->right)) + 1;
}

Node *left_rotate(Node *node)
{
	Node *root = node->right;
	if (!node || !root) return node;
	node->right = root->left;
	root->left = node;
	return root;
}

Node *right_rotate(Node *node)
{
	Node *root = node->left;
	if (!node || !root) return node;
	node->left = root->right;
	root->right = node;
	return root;
}

void print_tree(const Node *root, int level)
{
	if (!root) return;
	for (int i = 0; i < level; ++i)
		printf(i == level-1 ? "    ->" : "      ");
	printf("%2d(%1d)\n", root->value, root->height);
	print_tree(root->left, level+1);
	print_tree(root->right, level+1);
}

void print_inorder(const Node *root)
{
	if (!root) return;
	print_inorder(root->left);
	printf("%d, ", root->value);
	print_inorder(root->right);
}

void print_preorder(const Node *root)
{
	if (!root) return;
	printf("%d, ", root->value);
	print_preorder(root->left);
	print_preorder(root->right);
}

void print_postorder(const Node *root)
{
	if (!root) return;
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%d, ", root->value);
}

