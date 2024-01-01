#include "stack.h"
#include "expressions.h"

int main()
{
    printf("Infix: ");
    Queue *infix = read_expression();
    Queue *postfix = get_postfix(infix);
    delete_stack(infix);
    printf("Postfix:");
    for (int i = 0; i < postfix->top; ++i) {
        putchar(' ');
        print_string(postfix->array[i]);
    }
    putchar('\n');
    printf("Solution: %d\n", solve_postfix(postfix));
    delete_stack(postfix);
    return 0;
}
