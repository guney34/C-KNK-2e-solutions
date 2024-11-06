#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
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

void push(char i)
{
    if (is_full()) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    else
        contents[top++] = i;
}

char pop(void)
{
    if (is_empty()) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    else
        return contents[--top];
}

int main (void)
{
    printf("Enter parentheses and/or braces: ");
    
    char ch;
    while ((ch = (char)getchar()) != '\n') {
        switch (ch) {
            case '(': case '{':
                push(ch); break;
            case ')':
                if (pop() != '(') {
                    printf("Parentheses/braces are not nested properly\n");
                    goto end_loop;
                }
                break;
            case '}':
                if (pop() != '{') {
                    printf("Parentheses/braces are not nested properly\n");
                    goto end_loop;
                }
                break;
            default:
                break;
        }
    }
    end_loop:

    if(is_empty())
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not matched \n");
}