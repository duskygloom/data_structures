#include "circular_queue.h"

#include <stdio.h>

int main()
{
    Queue *queue = create_queue(5);
    print_queue(queue);
    enqueue(queue, 20);
    print_queue(queue);
    enqueue(queue, 30);
    print_queue(queue);
    enqueue(queue, 40);
    print_queue(queue);
    printf("Popped: %d\n", dequeue(queue));
    print_queue(queue);
    enqueue(queue, 50);
    print_queue(queue);
    enqueue(queue, 60);
    print_queue(queue);
    enqueue(queue, 70);
    print_queue(queue);
    delete_queue(queue);
    return 0;
}