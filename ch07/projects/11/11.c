#include <stdio.h>

int main(void)
{
    int ch;
    int initial;

    printf("Enter a first and last name: ");
    
    while ((ch = getchar()) == ' ') { }; //skip empty spaces
    initial = ch;
    while (getchar() != ' ') { }; //skip first name
    while ((ch = getchar()) == ' ') { }; //skip empty spaces

    do {
        putchar(ch);
    } while ((ch = getchar()) != '\n');

    putchar(',');
    putchar(' ');
    putchar(initial);
    putchar('.');
}