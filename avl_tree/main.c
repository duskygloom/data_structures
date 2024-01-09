#include "bst.h"

#include <stdio.h>

int get_user_choice();

int main()
{
	Node *root = NULL;
	int choice, value, length, running = 1;
	while (running) {
		choice = get_user_choice();
		switch (choice) {
			case 0:
				root = delete_tree(root);
				printf("Finished.\n");
				running = 0;
				break;
			case 1:
				printf("Number of values: ");
				scanf("%d", &length);
				printf("Values: ");
				for (int i = 0; i < length; ++i) {
					scanf("%d", &value);
					root = bst_insert(root, value);
					if (root) printf("Inserted %d into the tree.\n", value);
					else printf("Insufficient memory.\n");
				}
				break;
			case 2:
				if (!root) {
					printf("Tree is empty.\n");
					break;
				}
				printf("Value: ");
				scanf("%d", &value);
				root = bst_delete(root, value);
				printf("Deleted %d from tree.\n", value);
				break;
			case 3:
				if (!root) {
					printf("Tree is empty.\n");
					break;
				}
				printf("Value: ");
				scanf("%d", &value);
				Node *search = bst_search(root, value);
				if (search) printf("Found %d in the tree: %p\n", value, search);
				else printf("%d is not in the tree.\n", value);
				break;
			case 4:
				if (!root) {
					printf("Tree: []\n");
					break;
				}
				printf("Tree:\n");
				print_tree(root, 0);
				printf("Inorder:	[");
				print_inorder(root);
				printf("\b\b]\n");
				printf("Preorder:	[");
				print_preorder(root);
				printf("\b\b]\n");
				printf("Postorder:	[");
				print_postorder(root);
				printf("\b\b]\n");
				break;
			case 5:
				if (!root) {
					printf("Tree is empty.\n");
					break;
				}
				root = delete_tree(root);
				printf("Deleted all values.\n");
				break;
		}
	}
	return 0;
}

int get_user_choice()
{
	putchar('\n');
	printf("1. Insert.\n");
	printf("2. Delete.\n");
	printf("3. Search.\n");
	printf("4. Print.\n");
	printf("5. Delete all.\n");
	printf("   -------------------------\n");
	printf("0. Exit.\n");
	int choice;
	printf("Choose: ");
	scanf("%d", &choice);
	return choice;
}

