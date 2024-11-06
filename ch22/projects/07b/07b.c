#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    if (strcmp(".rle", argv[1] + strlen(argv[1]) - 4)) {
        printf("error: file extension should be .rle\n");
        exit(EXIT_FAILURE);
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *dest_str = malloc(strlen(argv[1])+1 - 4);
    strncpy(dest_str, argv[1], strlen(argv[1]) - 4);
    dest_str[strlen(argv[1]) - 4] = '\0';

    FILE *dest = fopen(dest_str, "wb");
    if (dest == NULL) {
        printf("%s can't be opened\n", dest_str);
        fclose(source);
        exit(EXIT_FAILURE);
    }
    free(dest_str);

    int count, ch;
    while ((count = fgetc(source)) != EOF) {
        if ((ch = fgetc(source)) == EOF)
            break;
        
        for (int i = 0; i < count; ++i)
            fputc(ch, dest);
    }

    fclose(dest);
    fclose(source);
}