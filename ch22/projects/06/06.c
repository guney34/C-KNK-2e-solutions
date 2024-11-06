#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    size_t offset = 0;
    unsigned char buffer[10];
    
    for(;;) {
        size_t n = fread(buffer, 1, 10, fp);
        if (n == 0)
            break;

        printf("%6zu  ", offset);
        for (size_t i = 0; i < n; ++i)
            printf("%.2X ", buffer[i]);

        for (size_t i = 0; i < 10 - n; ++i)
            printf("   ");

        putchar(' ');

        for (size_t i = 0; i < n; ++i)
            printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
        
        putchar('\n');
        offset += n;
    }

    fclose(fp);
}