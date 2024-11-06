#include <stdio.h>
#include <string.h>

#define STR_LEN 512

int main(void)
{
    char str[STR_LEN+1];
    char *words[sizeof(str)/2];
    int num_words = 0;

    printf("Enter a series of words: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (char *p = strtok(str, " "); p; p = strtok(NULL, " ")) {
        words[num_words] = p;
        ++num_words;
    }
    
    for (int i = num_words-1; i >= 0; --i)
        printf("%s ", words[i]);
}