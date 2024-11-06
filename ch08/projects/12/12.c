#include <stdio.h>
#include <ctype.h>

#define SIZE 26

int main(void)
{
    int ch;
    int value = 0;
    int let_val[SIZE] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");
    while ((ch = toupper(getchar())) != '\n') {
        value += let_val[ch - 'A'];
    }
    printf("Scrabble value: %d", value);
}