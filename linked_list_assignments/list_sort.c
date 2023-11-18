#include "single_linked_list.c"
#include <stdio.h>

int main()
{
    Node *list = create_list();
    insert(list, list->value, 12);
    insert(list, list->value, 4);
    insert(list, list->value, 2);
    insert(list, list->value, 10);
    insert(list, list->value, 26);
    insert(list, list->value, 6);
    printf("Normal list: ");
    print_list(list);
    putchar('\n');
    sort_list_ascending(list);
    printf("Sorted list (ascending): ");
    print_list(list);
    putchar('\n');
    sort_list_descending(list);
    printf("Sorted list (descending): ");
    print_list(list);
    putchar('\n');
    delete_list(list);
    return 0;
}