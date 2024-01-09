#ifndef TREE_H
#define TREE_H

typedef struct Node {
	int value;
	struct Node *left, *right;
} Node;

Node *create_node(int value);
Node *delete_node(Node *node);

Node *delete_tree(Node *node);

int height(const Node *node);

Node *left_rotate(Node *node);
Node *right_rotate(Node *node);

void print_tree(const Node *root, int level);

void print_inorder(const Node *root);
void print_preorder(const Node *root);
void print_postorder(const Node *root);

#endif

