#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: %s filename1 filename2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int ch;
    for (int i = 1; i < argc; ++i) {
        if ((fp = fopen(argv[i], "rb")) == NULL) {
            printf("\nerror: %s can't be opened\n", argv[i]);
            continue;
        }
        while ((ch = fgetc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }
}