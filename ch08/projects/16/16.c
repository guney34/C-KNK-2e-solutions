#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_LETTERS 26

int main(void)
{
    char ch;
    int A[NUM_LETTERS] = {0};
    bool anagram = true;

    printf("Enter first word: ");
    while((ch = getchar()) != '\n') {
        if (!isalpha(ch))
            continue;
        ++A[tolower(ch) - 'a'];
    }

    printf("Enter second word: ");
    while((ch = getchar()) != '\n') {
        if (!isalpha(ch))
            continue;
        --A[tolower(ch) - 'a'];
    }

    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (A[i]) {
            anagram = false;
            break;
        }
    }
    printf("The words are ");
    if (anagram)
        printf("anagrams.");
    else
        printf("not anagrams.");
}