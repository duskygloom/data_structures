#include "bst.h"

#include <stdlib.h>

Node *_bst_insert(Node *root, int value)
{
	if (!root) root = create_node(value);
	else if (value < root->value) root->left = bst_insert(root->left, value);
	else root->right = bst_insert(root->right, value);
	return root;
}

/**
 * @note
 * Updates the height of the nodes
 * in the path from root to value.
*/
int _update_path_height(Node *root, int value)
{
	if (!root) return 0;

	if (value < root->value) {
		int right_height = root->right ? root->right->height : 0;
		return root->height = 
			MAX(_update_path_height(root->left, value), right_height) + 1;
	}
	else if (value > root->value) {
		int left_height = root->left ? root->left->height : 0;
		return root->height = 
			MAX(_update_path_height(root->right, value), left_height) + 1;
	}
	else {
		int left_height = root->left ? root->left->height : 0;
		int right_height = root->right ? root->right->height : 0;
		return root->height = MAX(left_height, right_height) + 1;
	}
}

Node *bst_insert(Node *root, int value)
{
	root = _bst_insert(root, value);
	_update_path_height(root, value);
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
