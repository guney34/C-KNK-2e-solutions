#include <stdio.h>

#define SIZE 256

int main(void)
{
    char ch;
    char msg[SIZE] = {0};

    char *pos = msg;

    printf("Enter a message: ");
    while ((ch = (char)getchar()) != '\n' && pos < msg+SIZE)
        *pos++ = ch;

    printf("Reversal is: ");
    for (char *p = pos-1; p >= msg; --p)
        putchar(*p);
}