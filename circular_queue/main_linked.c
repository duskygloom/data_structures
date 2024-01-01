#include "circular_queue_linked.h"

#include <stdlib.h>

int get_user_choice();

int main()
{
    Queue *queue = NULL;

    bool running = true;

    while (running) {
        int choice = get_user_choice();
        int value;
        switch (choice) {
            case 0:
                if (queue) delete_queue(queue);
                running = false;
                break;
            case 1:
                if (queue) {
                    printf("A queue is already exists.\n");
                    printf("Delete the queue before creating another.\n");
                    break;
                }
                queue = create_queue();
                printf("Created a new queue.\n");
                break;
            case 2:
                if (!queue) {
                    printf("No queue exists.\n");
                    printf("Create a queue before deleting one.\n");
                    break;
                }
                delete_queue(queue);
                queue = NULL;
                printf("Deleted the queue.\n");
                break;
            case 3:
                if (!queue) {
                    printf("No queue exists.\n");
                    printf("Create a queue before pushing something into it.\n");
                    break;
                }
                printf("Value: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 4:
                if (!queue) {
                    printf("No queue exists.\n");
                    printf("Create a queue before popping something from it.\n");
                    break;
                }
                value = dequeue(queue);
                printf("Dequeued %d.\n", value);
                break;
            case 5:
                if (!queue) {
                    printf("No queue exists.\n");
                    printf("Create a queue before peeking into it.\n");
                    break;
                }
                printf("Front value: %d\n", peek_front(queue));
                printf("Rear value: %d\n", peek_rear(queue));
                break;
            case 6:
                if (!queue) {
                    printf("No queue exists.\n");
                    printf("Create a queue before printing it.\n");
                    break;
                }
                print_queue(queue);
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
    printf("1. Create queue.\n");
    printf("2. Delete queue.\n");
    printf("3. Enqueue.\n");
    printf("4. Dequeue.\n");
    printf("5. Peek.\n");
    printf("6. Print.\n");
    printf("0. Exit.\n");
    printf("Response: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}
