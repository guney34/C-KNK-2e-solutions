#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch;
    int count = 0;
    bool in_word = false;
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch))
            in_word = false;
        else if (!in_word) {
            ++count;
            in_word = true;
        }
    }

    fclose(fp);
    printf("%s contains %d words\n", argv[1], count);
}