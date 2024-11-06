#include <stdio.h>
#include <stdlib.h>
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
    while ((ch = fgetc(fp)) != EOF)
        if (ch == '\n')
            ++count;

    if (!ferror(fp)) //count last line, which doesn't end with '\n'
        ++count;

    fclose(fp);
    printf("%s contains %d lines\n", argv[1], count);
}