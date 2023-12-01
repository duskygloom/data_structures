#include "stack.h"
#include "expressions.h"

#include <ctype.h>
#include <stdbool.h>

bool same_string(char *str1, char *str2)
{
    for (; *str1 && *str2 && *str1 == *str2; ++str1 && ++str2);
    return *str1 == 0 && *str2 == 0;
}

Priority get_priority(char *operator)
{
    if (same_string(operator, "^"))
        return HIGH_PRIORITY;
    else if (same_string(operator, "*") || same_string(operator, "/") || same_string(operator, "%%"))
        return MID_PRIORITY;
    else if (same_string(operator, "+") || same_string(operator, "-"))
        return LOW_PRIORITY;
    return NO_PRIORITY;
}



Stack *get_expression()
{
    Stack *expression = create_stack(MAX_TOKENS);
    int ch, operand = 0;
    while ((ch = getchar()) != '\n') {
        if (isdigit(ch));
    }
    return expression;
}

Stack *get_postfix_from_infix(Stack *infix)
{
    int *array = infix->array;
    int length = infix->maxsize;
    Stack *postfix  = create_stack(length);
    Stack *op_stack = create_stack(length);
    for (int i = 0; i < length; ++i) {
        Priority p = get_priority(array[i]);
        // if opening bracket, simply push to op_stack
        if (same_string(array[i], "("))
            push(op_stack, array[i]);
        // if closing bracket, evaluate till the opening bracket
        else if (same_string(array[i], ")")) {
            char *top = pop(op_stack);
            while (!same_string(top, "(")) {
                push(postfix, top);
                top = pop(op_stack);
            }
        }
        // if it is not an operator
        else if (p == NO_PRIORITY)
            push(postfix, array[i]);
        // if it is a less prior operator
        else if (is_empty_stack(op_stack) || same_string(peek(op_stack), "(") || p < get_priority(peek(op_stack)))
            push(op_stack, array[i]);
        // same or more prior operator
        else {
            while (!is_empty_stack(op_stack))
                push(postfix, pop(op_stack));
            push(op_stack, array[i]);
        }
    }
    while (!is_empty_stack(op_stack))
        push(postfix, pop(op_stack));
    delete_stack(op_stack);
    return postfix;
}