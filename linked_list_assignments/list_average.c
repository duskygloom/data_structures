#include <stdio.h>
#include "single_linked_list.c"

int main()
{
    printf("Length of list: ");
    int length, value, i;
    scanf("%d", &length);
    Node *list = create_list();
    printf("Values: ");
    for (i = 0; i < length; ++i) {
        scanf("%d", &value);
        insert(list, i, value);
    }
    printf("List: ");
    print_list(list);
    putchar('\n');
    // placing sum in value
    value = 0;
    for (i = 0; i < length; ++i) value += get_value(list, i);
    double average;
    if (length > 0) average = (double)value / length;
    else average = 0;
    printf("Average: %.2lf\n", average);
    delete_list(list);
    return 0;
}
