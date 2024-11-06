#include <stdio.h>
#include <ctype.h>

int main(void)
{
    bool in_word = false;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (!in_word && !isspace(ch) && !ispunct(ch)) {
            in_word = true;
            ch = toupper(ch);
        } else if (isspace(ch) || ispunct(ch)) {
            in_word = false;
        }
        putchar(ch);
    }
}