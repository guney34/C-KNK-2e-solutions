#include <stdlib.h>
#include <stdio.h>

#define KEY '&'

int main(int argc, char *argv[])
{

    if (argc != 3) {
        printf("usage: %s source dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        printf("%s can't be opened\n", argv[2]);
        fclose(source);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(source)) != EOF)
        fputc(ch ^ KEY, dest);

    fclose(source);
    fclose(dest);
}
