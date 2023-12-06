#include "expressions.h"

int main()
{
    printf("Expression: ");
    Stack *expression = get_expression();
    print_stack(expression);
    return 0;
}
