#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_WORDS 100

int read_line(char str[], int n);
void selection_sort(char *a[], int n);

int main(void)
{
    char *words[MAX_WORDS];
    int num_words = 0; 

    for (;;) {
        if (num_words == MAX_WORDS) {
            printf("no space left\n");
            break;
        }
        printf("Enter word: ");
        words[num_words] = malloc(WORD_LEN + 1);
        if (words[num_words] == NULL) {
            printf("failed to allocate memory\n");
            break;
        }
        if (!read_line(words[num_words], WORD_LEN))
            break;
        ++num_words;          
    }
    selection_sort(words, num_words);

    printf("In sorted order: ");
    for (int i = 0; i < num_words; ++i)
        printf("%s ", words[i]);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = (char)ch;
    str[i] = '\0';
    return i;
}

void selection_sort(char *a[], int n)
{
    if (n < 1) 
        return;

    int max = 0;
    for (int i = 1; i < n; ++i) 
        if (strcmp(a[i], a[max]) > 0) 
            max = i;

    char *temp = a[n-1];
    a[n-1] = a[max];
    a[max] = temp;

    selection_sort(a, n-1);
}