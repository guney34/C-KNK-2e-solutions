#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *dest_str = malloc(strlen(argv[1]) + 4);
    strcpy(dest_str, argv[1]);
    strcat(dest_str, ".rle");

    FILE *dest = fopen(dest_str, "wb");
    if (dest == NULL) {
        printf("%s can't be opened\n", dest_str);
        fclose(source);
        exit(EXIT_FAILURE);
    }
    free(dest_str);

    int count = 0;
    int ch = fgetc(source);
    int last_ch = ch;

    if (ch != EOF)
        ++count;

    while((ch = fgetc(source)) != EOF) {
        if (ch == last_ch) {
            ++count;
        } else {
            fputc(count, dest);
            fputc(last_ch, dest);
            count = 1;
        }
        last_ch = ch;
    }

    if (count > 0) {
        fputc(count, dest);
        fputc(last_ch, dest);
    }

    fclose(source);
    fclose(dest);
}