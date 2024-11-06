#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define NUM_LETTERS 26
#define WORD_LEN 100

bool are_anagrams(const char *word1, const char *word2)
{
    int letters[NUM_LETTERS] = {0};

    while (*word1) {
        if (isalpha(*word1))
            ++letters[tolower(*word1) - 'a'];
        ++word1;
    }
    while (*word2) {
        if (isalpha(*word2))
            --letters[tolower(*word2) - 'a'];
        ++word2;
    }
    for (int i = 0; i < NUM_LETTERS; ++i)
        if (letters[i])
            return false;
    return true;
}

int main(void)
{
    char first_word[WORD_LEN + 1];
    char second_word[WORD_LEN + 1];

    printf("Enter first word: ");
    fgets(first_word, sizeof(first_word), stdin);
    first_word[strcspn(first_word, "\n")] = '\0';

    printf("Enter second word: ");
    fgets(second_word, sizeof(second_word), stdin);
    second_word[strcspn(second_word, "\n")] = '\0';

    printf("The words are ");
    if (are_anagrams(first_word, second_word))
        printf("anagrams.");
    else
        printf("not anagrams.");
}