#include <stdio.h>

#define SIZE 128

int main(void)
{
    char sentence[SIZE] = {0};
    char ch;
    char ter;
    int len = 0;

    printf("Enter a sentence: ");

    for (int i = 0; i < SIZE; ++i) {
        ch = (char)getchar();
        if (ch == '.' || ch == '?' || ch == '!') {
            ter = ch;
            break;
        }
        sentence[i] = ch;
        ++len;
    }

    printf("Reversal of sentence: ");

    int i = len - 1;
    while (i >= 0) {
        if (sentence[i] == ' ')
            --i;

        int word_len = 0;
        for (int j = i; sentence[j] != ' ' && j >= 0; --j)
            ++word_len;
        
        for (int k = i - word_len + 1; k <= i; ++k)
            putchar(sentence[k]);

        i -= word_len;
        if (word_len > 0 && i >= 0)
            putchar(' ');
    }
    putchar(ter);
}