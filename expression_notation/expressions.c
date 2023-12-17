#include "stack.h"
#include "expressions.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool samestr(const String *str, const char *cstr)
{
    char *str1 = str->cstring;
    for (; *str1 && *cstr && *str1 == *cstr; ++str1 && ++cstr);
    return *str1 == 0 && *cstr == 0;
}

Priority get_priority(const String *operator)
{
    if (operator->length != 1)
        return NO_PRIORITY;
    char ch = operator->cstring[0];
    switch (ch) {
        case '^':
            return HIGH_PRIORITY;
        case '*':
        case '/':
        case '%':
            return MID_PRIORITY;
        case '+':
        case '-':
            return LOW_PRIORITY;
        default:
            return NO_PRIORITY;
    }
}

static inline bool is_operator(int ch)
{
    return ch == '^' || ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-';
}

Stack *read_expression()
{
    char *operators[] = {"+", "-", "*", "/", "%%", "^"};
    Stack *expression = create_stack(MAX_TOKENS);
    String *buffer = create_empty_string(5);
    int ch = getchar();
    while (ch != '\n' && ch != EOF) {
        if (isdigit(ch)) {
            while (isdigit(ch)) {
                append_char(buffer, ch);
                ch = getchar();
            }
            push(expression, create_string(buffer->cstring));
            assign_cstr(buffer, "");
        }
        else if (is_operator(ch)) {
            append_char(buffer, ch);
            push(expression, create_string(buffer->cstring));
            assign_cstr(buffer, "");
            ch = getchar();
        }
        else if (ch == '(' || ch == ')') {
            append_char(buffer, ch);
            push(expression, create_string(buffer->cstring));
            assign_cstr(buffer, "");
            ch = getchar();
        }
        else ch = getchar();
    }
    delete_string(buffer);
    return expression;
}

/**
 * @note
 * An operator will be pushed to opstack if opstack is empty
 * or if there is a opening bracket at top of opstack
 * or if the priority of operator is higher than the top.
*/
static inline bool to_opstack(const Stack *opstack, Priority p)
{
    return is_empty_stack(opstack) || samestr(peek(opstack), "(") || p > get_priority(peek(opstack));
}

Stack *get_postfix(const Stack *infix)
{
    String **array = infix->array;
    int length = infix->top;
    Stack *postfix  = create_stack(length);
    Stack *opstack = create_stack(length);
    for (int i = 0; i < length && array[i]; ++i) {
        Priority p = get_priority(array[i]);
        if (samestr(array[i], "("))
            push(opstack, array[i]);
        else if (samestr(array[i], ")")) {
            String *top = pop(opstack);
            while (!samestr(top, "(")) {
                push(postfix, top);
                top = pop(opstack);
            }
        }
        else if (p == NO_PRIORITY)
            push(postfix, array[i]);
        else if (to_opstack(opstack, p))
            push(opstack, array[i]);
        // same or more prior operator
        else {
            while (!to_opstack(opstack, p)) push(postfix, pop(opstack));
            push(opstack, array[i]);
        }
    }
    while (!is_empty_stack(opstack))
        push(postfix, pop(opstack));
    delete_stack(opstack);
    return postfix;
}

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

int solve_postfix(const Stack *postfix)
{
    int result = 0;
    char buffer[MAX_TOKEN_LEN+1];
    int length = postfix->top;
    Stack *opstack = create_stack(length);
    for (int i = 0; i < length; ++i) {
        if (get_priority(postfix->array[i]) == NO_PRIORITY)
            push(opstack, postfix->array[i]);
        else {
            int operator = postfix->array[i]->cstring[0];
            int operand1 = atoi(pop(opstack)->cstring);
            int operand2 = atoi(pop(opstack)->cstring);
            switch (operator) {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
                case '%':
                    result = operand2 % operand1;
                    break;
                case '^':
                    result = power(operand2, operand1);
                    break;
                default:
                    printf("[Error] Invalid operator: %c\n", operator);
                    result = 0;
                    break;
            }
            sprintf(buffer, "%*d", MAX_TOKEN_LEN, result);
            push(opstack, create_string(buffer));
        }
    }
    delete_stack(opstack);
    return result;
}
