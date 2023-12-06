#include "stack.h"
#include "expressions.h"

int main()
{
    char *infix[] = {"12", "+", "7", "-", "(", "10", "*", "2", "+", "5", ")"};
    Stack *postfix = create_stack(sizeof(infix)/sizeof(char *));
    get_postfix_from_infix(infix, postfix, sizeof(infix)/sizeof(char *));
    print_stack(postfix);
    delete_stack(postfix);
    return 0;
}
