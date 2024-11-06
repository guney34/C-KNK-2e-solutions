#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 20

int read_line(char str[], int n);

int main(void)
{
    char word[MAX_WORD_SIZE + 1];
    char smallest_word[MAX_WORD_SIZE + 1];
    char largest_word[MAX_WORD_SIZE + 1];

    printf("Enter word: ");
    int word_len = read_line(word, MAX_WORD_SIZE);

    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (word_len != 4) {
        printf("Enter word: ");
        word_len = read_line(word, MAX_WORD_SIZE);

        if (strcmp(word, smallest_word) < 0)
            strcpy(smallest_word, word);
        if (strcmp(word, largest_word) > 0)
            strcpy(largest_word, word);
    }
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) == ' ')
        ;
    while (ch != '\n') {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}