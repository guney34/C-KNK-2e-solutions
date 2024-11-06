#include <stdio.h>

#define SIZE 128
#define WORDS 30
#define WORD_LEN 20


int main(void)
{
    char ch;
    char ter = '\0';
    char sentence[WORDS][WORD_LEN + 1];
    char (*word)[WORD_LEN + 1];

    printf("Enter a sentence: ");
    for (word = sentence; word < sentence + WORDS - 1; ++word) {
        for(char *character = *word; character <  *(word + 1); ++character) {
            ch = (char)getchar();

            if (ch == ' ') {
                *character = '\0';
                break;
            }
            if (ch == '.' || ch == '?' || ch == '!') {
                ter = ch;
                *character = '\0';
                goto end_loop;
            }
            *character = ch;
        }
    }
    end_loop:

    printf("Reversal of sentence: ");
    while (word > sentence) {
        printf("%s ", *word);
        --word;
    }
    printf("%s%c", *word, ter);
}