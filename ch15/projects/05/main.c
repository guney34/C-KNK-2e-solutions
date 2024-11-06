#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    for (;;) {   
        make_empty();
        printf("Enter an RPN expression: ");

        char ch;
        scanf(" %c", &ch);
        while (ch != '\n') {
            switch(ch) {
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    push((int)(ch - '0'));
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
                    printf("Value of expression: %d\n", pop());
                    goto end_loop;
                case ' ': case '\t':
                    continue;
                default:
                    exit(EXIT_SUCCESS);
            }
            end_loop:
            scanf(" %c", &ch);
        }
    }
}