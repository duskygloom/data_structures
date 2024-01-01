#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_user_choice(void);

int main()
{
    int running = true;
    Node *tree = NULL;

    while (running) {
        int response = get_user_choice();
        int value, length;

        switch (response) {
            case 0:
                if (tree) delete_tree(tree);
                running = false;
                break;
            case 1:
                if (tree) {
                    printf("A tree already exists.\n");
                    printf("Delete the tree before creating another tree.\n");
                    break;
                }
                printf("Number of elements: ");
                scanf("%d", &length);
                printf("Elements: ");
                if (length < 1) {
                    printf("Tree must have at least 1 element.\n");
                    break;
                }
                scanf("%d", &value);
                tree = create_node(value);
                printf("Elements: ");
                for (int i = 1; i < length; ++i) {
                    scanf("%d", &value);
                    insert(tree, value);
                }
                printf("Created the tree.\n");
                break;
            case 2:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to delete it.\n");
                    break;
                }
                delete_tree(tree);
                tree = NULL;
                printf("Deleted tree.\n");
                break;
            case 3:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to print it.\n");
                    break;
                }
                printf("Preorder:");
                print_preorder(tree);
                putchar('\n');
                break;
            case 4:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to print it.\n");
                    break;
                }
                printf("Inorder:");
                print_inorder(tree);
                putchar('\n');
                break;
            case 5:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to print it.\n");
                    break;
                }
                printf("Reverse inorder:");
                print_reverse_inorder(tree);
                putchar('\n');
                break;
            case 6:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to print it.\n");
                    break;
                }
                printf("Postorder:");
                print_postorder(tree);
                putchar('\n');
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

int get_user_choice(void)
{
    putchar('\n');
    printf("1. Create.\n");
    printf("2. Delete.\n");
    printf("3. Preorder.\n");
    printf("4. Inorder.\n");
    printf("5. Reverse inorder.\n");
    printf("6. Postorder.\n");
    printf("0. Exit.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}
