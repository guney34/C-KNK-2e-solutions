#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    }
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    }
    else
        return contents[--top];
}

int evaluate_RPN_expression(const char *expression)
{
    for (; *expression; ++expression) {
        switch(*expression) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                push((int)(*expression - '0'));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-': {
                int right_operand = pop();
                push(pop() - right_operand);
                break;
            }
            case '/': {
                int right_operand = pop();
                push(pop() / right_operand);
                break;
            }
            case '=':
                return pop();
                break;
            case ' ': case '\t':
                continue;
            default:
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

int main(void)
{
    for (;;) {   
        make_empty();
        printf("Enter an RPN expression: ");
        char expression[STACK_SIZE+1];
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = '\0';


        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    }
}
