#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
    struct node *next;
    char word[];
};

struct node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    while (line != NULL) {
        struct node *temp = line;
        line = line->next;
        free(temp);
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct node *new_word = malloc(sizeof(struct node) + strlen(word) + 1);
    if (new_word == NULL) {
        printf("failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_word->word, word);
    new_word->next = NULL;

    struct node **p = &line;
    while (*p != NULL)
        p = &(*p)->next;
    *p = new_word;

    line_len += strlen(word);
    if (num_words > 0)
        ++line_len;
    ++num_words;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces;
    extra_spaces = MAX_LINE_LEN - line_len;

    struct node *p = line;
    while(p != NULL) {
        printf("%s", p->word);
        if (num_words > 1) {
            int spaces_to_insert = extra_spaces / (num_words - 1);
            for (int i = 1; i <= spaces_to_insert + 1; ++i)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
        }
        --num_words;
        p = p->next;
    }
    putchar('\n');
}

void flush_line(void)
{
    struct node *p = line;
    while (p != NULL) {
        printf("%s", p->word);
        if (p->next != NULL)
            putchar(' ');
        p = p->next;
    }
    putchar('\n');
}