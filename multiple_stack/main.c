#include "left_multistack.h"

#include <stdio.h>

#define MAXSTACKLEN 20
#define NUMSTACKS   4

int main()
{
    // creating multistack
    MultiStack *multistack = create_multistack(NUMSTACKS, MAXSTACKLEN);
    int stack, value;
    int response = get_response(NUMSTACKS, MAXSTACKLEN);
    while (response != 6) {
        switch (response) {
            case 1:
                printf("Stack: ");
                scanf("%d", &stack);
                printf("Value: ");
                scanf("%d", &value);
                if (!push(multistack, stack, value))
                    printf("Could not push.\n");
                break;
            case 2:
                printf("Stack: ");
                scanf("%d", &stack);
                printf("Popped %d.\n", pop(multistack, stack));
                break;
            case 3:
                printf("Stack: ");
                scanf("%d", &stack);
                printf("Top value: %d.\n", peek(multistack, stack));
                break;
            case 4:
                printf("Stack: ");
                scanf("%d", &stack);
                print_stack(multistack, stack);
                break;
            case 5:
                print_multistack(multistack);
                break;
            default:
                printf("Invalid response.\n");
                break;
        }
        response = get_response(NUMSTACKS, MAXSTACKLEN);
    }
    delete_multistack(multistack);
    return 0;
}
