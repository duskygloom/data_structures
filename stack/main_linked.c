#include "stack_linked.h"

int get_user_choice();

int main()
{
    Queue *stack = NULL;

    bool running = true;

    while (running) {
        int choice = get_user_choice();
        int value;
        switch (choice) {
            case 0:
                if (stack) delete_stack(stack);
                running = false;
                break;
            case 1:
                if (stack) {
                    printf("A stack is already exists.\n");
                    printf("Delete the stack before creating another.\n");
                    break;
                }
                stack = create_stack();
                printf("Created a new stack.\n");
                break;
            case 2:
                if (!stack) {
                    printf("No stack exists.\n");
                    printf("Create a stack before deleting one.\n");
                    break;
                }
                delete_stack(stack);
                stack = NULL;
                printf("Deleted the stack.\n");
                break;
            case 3:
                if (!stack) {
                    printf("No stack exists.\n");
                    printf("Create a stack before pushing something into it.\n");
                    break;
                }
                printf("Value: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 4:
                if (!stack) {
                    printf("No stack exists.\n");
                    printf("Create a stack before popping something from it.\n");
                    break;
                }
                value = pop(stack);
                printf("Popped %d.\n", value);
                break;
            case 5:
                if (!stack) {
                    printf("No stack exists.\n");
                    printf("Create a stack before peeking into it.\n");
                    break;
                }
                value = peek(stack);
                printf("Top value: %d\n", value);
                break;
            case 6:
                if (!stack) {
                    printf("No stack exists.\n");
                    printf("Create a stack before printing it.\n");
                    break;
                }
                print_stack(stack);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

int get_user_choice()
{
    putchar('\n');
    printf("1. Create stack.\n");
    printf("2. Delete stack.\n");
    printf("3. Push.\n");
    printf("4. Pop.\n");
    printf("5. Peek.\n");
    printf("6. Print.\n");
    printf("0. Exit.\n");
    printf("Response: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}
