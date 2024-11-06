#include <stdio.h>

#define SIZE 128

int main(void)
{
    char sentence[SIZE] = {0};
    char ch;
    char ter;
    char *len = sentence;

    printf("Enter a sentence: ");
    while ((ch = (char)getchar()) != '\n' && len < sentence+SIZE) {
        if (ch == '.' || ch == '?' || ch == '!') {
            ter = ch;
            break;
        }
        *len++ = ch;
    }

    printf("Reversal of sentence: ");

    for (char *p = len-1; p >= sentence; --p) {
        if (*p == ' ')
            continue;

        int word_len = 0;
        for (char *q = p; *q != ' ' && q >= sentence; --q)
            ++word_len;
        
        for (char *q = p-word_len+1; q <= p; ++q)
            putchar(*q);

        p -= word_len;
        if (word_len > 0 && p >= sentence)
            putchar(' ');
    }
    putchar(ter);
}