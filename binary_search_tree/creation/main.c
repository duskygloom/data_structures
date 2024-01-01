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
                printf("Root: ");
                scanf("%d", &value);
                tree = create_node(value);
                printf("Created root of the tree.\n");
                printf("Root of a tree cannot be deleted without deleting the entire tree.\n");
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
                    printf("Create a tree to insert into it.\n");
                    break;
                }
                printf("Number of elements: ");
                scanf("%d", &length);
                printf("Elements: ");
                for (int i = 0; i < length; ++i) {
                    scanf("%d", &value);
                    insert(tree, value);
                }
                printf("Inserted value into the tree.\n");
                break;
            case 4:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to remove from it.\n");
                    break;
                }
                printf("Value: ");
                scanf("%d", &value);
                remove_node(tree, NULL, value);
                printf("Removed value from the tree.\n");
                break;
            case 5:
                if (!tree) {
                    printf("No tree exists.\n");
                    printf("Create a tree to print it.\n");
                    break;
                }
                printf("Tree:\n");
                print_tree(tree, 0);
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
    printf("3. Insert.\n");
    printf("4. Remove.\n");
    printf("5. Print.\n");
    printf("0. Exit.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}
