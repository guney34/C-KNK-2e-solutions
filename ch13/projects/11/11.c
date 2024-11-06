#include <stdio.h>
#include <string.h>

#define SENTENCE_LEN 256

double compute_average_word_length(const char *sentence)
{
    int words = 0;
    int letters = 0;

    while (*sentence) {
        if (*sentence == ' '){
            ++sentence;
            continue;
        }
        while (*sentence != ' ' && *sentence) {
            ++letters;
            ++sentence;
        }
        ++words;
        ++sentence;
    }
    return (double)letters / (double)words;
}

int main(void)
{
    char sentence[SENTENCE_LEN + 1];
    printf("Enter an sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    printf("Average word length: %.1lf\n", compute_average_word_length(sentence));
}