#include "stack.h"
#include "expressions.h"

int main()
{
    printf("Expression: ");
    Stack *infix = get_expression();
    Stack *postfix = get_postfix_from_infix(infix);
    delete_stack(infix);
    print_stack(postfix);
    delete_stack(postfix);
    return 0;
}
