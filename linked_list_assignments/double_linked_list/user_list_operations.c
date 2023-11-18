#include <stdio.h>
#include "double_linked_list.c"

int get_user_choice();
int get_traversal_choice();
int get_insertion_choice();
int get_deletion_choice();
int get_sorting_choice();

int main()
{
    Node *list = create_list();
    int keep_running = 1, index, value;
    while (keep_running) {
        int response = get_user_choice();
        switch (response) {
            case 0:
                delete_list(list);
                keep_running = 0;
                break;
            case 1:
                int traversal_response = get_traversal_choice();
                switch (traversal_response) {
                    case 1:
                        print_list(list);
                        break;
                    case 2:
                        printf("Length: %d\n", count_list(list));
                        break;
                }
                break;
            case 2:
                int insertion_response = get_insertion_choice();
                switch (insertion_response) {
                    case 1:
                        printf("Value: ");
                        scanf("%d", &value);
                        prepend(list, value);
                        break;
                    case 2:
                        printf("Value: ");
                        scanf("%d", &value);
                        append(list, value);
                        break;
                    case 3:
                        printf("Index, value: ");
                        scanf("%d %d", &index, &value);
                        insert(list, index, value);
                        break;
                }
                break;
            case 3:
                int deletion_response = get_deletion_choice();
                switch (deletion_response) {
                    case 1:
                        printf("Popped value: %d\n", pop_left(list));
                        break;
                    case 2:
                        printf("Popped value: %d\n", pop_right(list));
                        break;
                    case 3:
                        printf("Index: ");
                        scanf("%d", &index);
                        printf("Deleted value: %d\n", delete(list, index));
                        break;
                }
                break;
            case 4:
                int sorting_response = get_sorting_choice();
                switch (sorting_response) {
                    case 1:
                        ascending_sort(list);
                        print_list(list);
                        break;
                    case 2:
                        descending_sort(list);
                        print_list(list);
                        break;
                }
                break;
        }
    }
    return 0;
}

int get_user_choice()
{
    putchar('\n');
    printf("1. Traversal.\n");
    printf("2. Insertion.\n");
    printf("3. Deletion.\n");
    printf("4. Sorting.\n");
    printf("0. Delete the list and exit.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}

int get_traversal_choice()
{
    printf("1. Print list.\n");
    printf("2. Count nodes.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}

int get_insertion_choice()
{
    printf("1. Insert at start.\n");
    printf("2. Insert at end.\n");
    printf("3. Insert at any position.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}

int get_deletion_choice()
{
    printf("1. Delete from start.\n");
    printf("2. Delete from end.\n");
    printf("3. Delete from any position.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}

int get_sorting_choice()
{
    printf("1. Sort ascending.\n");
    printf("2. Sort descending.\n");
    printf("Response: ");
    int response;
    scanf("%d", &response);
    return response;
}
