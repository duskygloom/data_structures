#include "bst.h"

#include <stdlib.h>

Node *bst_insert(Node *root, int value)
{
	if (!root) root = create_node(value);
	else if (value < root->value) root->left = bst_insert(root->left, value);
	else root->right = bst_insert(root->right, value);
	return root;
}

Node *bst_delete(Node *root, int value)
{
	if (!root) return NULL;

	if (value < root->value) 
		root->left = bst_delete(root->left, value);
	else if (value > root->value) 
		root->right = bst_delete(root->right, value);
	else if (root->left) {
		Node *prev = root;
		Node *candidate = root->left;
		while (candidate->right) {
			prev = candidate;
			candidate = candidate->right;
		}
		int temp = candidate->value;
		candidate->value = root->value;
		root->value = temp;
		if (prev == root)
			prev->left = bst_delete(candidate, value);
		else prev->right = bst_delete(candidate, value);
	}
	else if (root->right) {
		Node *prev = root;
		Node *candidate = root->right;
		while (candidate->left) candidate = candidate->left;
		int temp = candidate->value;
		candidate->value = root->value;
		root->value = temp;
		if (prev == root)
			prev->right = bst_delete(candidate, value);
		else prev->left = bst_delete(candidate, value);
	}
	else root = delete_node(root);

	return root;
}

Node *bst_search(Node *root, int value)
{
	if (!root) return NULL;
	if (value < root->value) 
		return bst_search(root->left, value);
	else if (value > root->value) 
		return bst_search(root->right, value);
	else return root;
}

