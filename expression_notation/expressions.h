#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include "stack.h"

/**
 * @note
 * The maximum number of tokens in an expression.
*/
#define MAX_TOKENS      100
#define MAX_TOKEN_LEN   10

/**
 * @note
 * NO_PRIORITY means it is not an operator.
*/
typedef enum PRIORITY {
    NO_PRIORITY, 
    LOW_PRIORITY, 
    MID_PRIORITY, 
    HIGH_PRIORITY
} Priority;

Priority get_priority(const String *operator);

Queue *read_expression();

Queue *get_postfix(const Queue *infix);

int solve_postfix(const Queue *postfix);

#endif
