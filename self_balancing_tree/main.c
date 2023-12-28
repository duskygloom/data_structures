#include "tree.h"

#include <stdio.h>

int main()
{
    int array[] = {11, 13, 12, 9, 15, 16, 17, 8, 7, 3, 19, 4, 19, 19};
    Node *tree = create_tree(array, sizeof(array)/sizeof(int));
    print_inorder(tree);
    printf("Height: %d\n", get_height(tree));
    delete_tree(tree);
    return 0;
}