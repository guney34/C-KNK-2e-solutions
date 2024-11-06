#include <stdio.h>

#define SIZE 20
int main(void)
{
    int ch;
    int initial;
    char surname[SIZE] = {0};

    printf("Enter a first and last name: ");
    
    while ((ch = getchar()) == ' ') { }; //skip empty spaces
    initial = ch;
    while (getchar() != ' ') { }; //skip first name
    while ((ch = getchar()) == ' ') { }; //skip empty spaces

    for (int i = 0; i < SIZE; ++i) {
        surname[i] = ch;
        ch = getchar();
        if (ch == '\n' || ch == ' ')
            break;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (surname[i])
            putchar(surname[i]);
    }
    putchar(',');
    putchar(' ');
    putchar(initial);
    putchar('.');
}