#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line_str[MAX_LINE_LEN+1];
    while (fgets(line_str, sizeof(line_str), fp) != NULL) {
        char n[10];
        int i = 0;

        for (char *cp = line_str; *cp != '\n'; ++cp) {
            if (!isdigit((int)*cp) || i > 9)
                continue;
            n[i++] = *cp;
        }

        printf("(%c%c%c) %c%c%c-%c%c%c%c\n",
               n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9]);
    }

    fclose(fp);
}
