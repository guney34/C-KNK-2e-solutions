#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full()) {
        printf("Expression is too complex\n");
        exit(EXIT_FAILURE);
    } else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    } else
        return contents[--top];
}