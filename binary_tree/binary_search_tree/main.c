#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int length, value;
    printf("Number of elements: ");
    scanf("%d", &length);
    Node *root;
    printf("Elements: ");
    if (length >= 1) {
        scanf("%d", &value);
        root = create_node(value);
    }
    for (int i = 1; i < length; ++i) {
        scanf("%d", &value);
        insert(root, value);
    }
    
    printf("Inorder:");
    print_inorder(root);
    putchar('\n');
    printf("Reverse inorder:");
    print_reverse_inorder(root);
    putchar('\n');
    printf("Preorder:");
    print_preorder(root);
    putchar('\n');
    printf("Postorder:");
    print_postorder(root);
    putchar('\n');

    int toremove;
    printf("\nRemove ");
    scanf("%d", &toremove);
    remove_node(root, NULL, toremove);
    printf("Inorder:");
    print_inorder(root);
    putchar('\n');
    printf("Reverse inorder:");
    print_reverse_inorder(root);
    putchar('\n');
    printf("Preorder:");
    print_preorder(root);
    putchar('\n');
    printf("Postorder:");
    print_postorder(root);
    putchar('\n');
    return 0;
}
