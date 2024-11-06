#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SENTENCE_LEN 256

int compute_vowel_count(const char *sentence)
{
    int count = 0;
    while (*sentence) {
        switch(toupper(*sentence)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                ++count;
                break;
            default:
                break;
        }
        ++sentence;
    }
    return count;
}

int main(void)
{
    char sentence[SENTENCE_LEN+1];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
}