#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

int main (void)
{

    Stack stack = create();

    printf("Enter parentheses and/or braces: ");
    
    char ch;
    while ((ch = (char)getchar()) != '\n') {
        switch (ch) {
            case '(': case '{':
                push(stack, ch);
                break;
            case ')':
                if (pop(stack) != '(') {
                    printf("Parentheses/braces are not nested properly\n");
                    goto end_loop;
                }
                break;
            case '}':
                if (pop(stack) != '{') {
                    printf("Parentheses/braces are not nested properly\n");
                    goto end_loop;
                }
                break;
            default:
                break;
        }
    }
    end_loop:

    if (is_empty(stack))
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not matched \n");
}