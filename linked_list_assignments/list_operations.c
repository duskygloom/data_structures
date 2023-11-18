#include <stdio.h>
#include "linked_list.c"

int main()
{
    Node *list = create_list();
    insert(list, list->value, 10);
    insert(list, list->value, 20);
    insert(list, list->value, 30);
    insert(list, list->value, 40);
    delete(list, 1);
    printf("List value: %d\n", get_value(list, 1));
    printf("List: ");
    print_list(list);
    delete_list(list);
    return 0;
}
