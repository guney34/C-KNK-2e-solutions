#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    Stack stack = create();

    for (;;) {   
        make_empty(stack);
        printf("Enter an RPN expression: ");

        char ch;
        scanf(" %c", &ch);
        while (ch != '\n') {
            switch(ch) {
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    push(stack, (int)(ch - '0'));
                    break;
                case '+':
                    push(stack, pop(stack) + pop(stack));
                    break;
                case '*':
                    push(stack, pop(stack) * pop(stack));
                    break;
                case '-': {
                    int right_operand = pop(stack);
                    push(stack, pop(stack) - right_operand);
                    break;
                }
                case '/': {
                    int right_operand = pop(stack);
                    push(stack, pop(stack) / right_operand);
                    break;
                }
                case '=':
                    printf("Value of expression: %d\n", pop(stack));
                    goto end_loop;
                case ' ': case '\t':
                    continue;
                default:
                    exit(EXIT_SUCCESS);
            }
            scanf(" %c", &ch);
        }
        end_loop:
    }
}