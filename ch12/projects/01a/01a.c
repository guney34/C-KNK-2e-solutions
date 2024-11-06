#include <stdio.h>

#define SIZE 256

int main(void)
{
    char ch;
    char msg[SIZE] = {0};
    size_t len = 0;

    printf("Enter a message: ");
    while ((ch = (char)getchar()) != '\n' && len < SIZE) {
        msg[len++] = ch;
    }
    printf("Reversal is: ");
    for (int i = len-1; i >= 0; --i)
        putchar(msg[i]);
}