#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 3) {
        fprintf(stderr, "usage: %s source dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *fp_out = fopen(argv[2], "wb");
    if (fp_out == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[2]);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch == '\r' && ch == '\x1a')
            continue;
        fputc(ch, fp_out);
    }
    
    fclose(fp_in);
    fclose(fp_out);
}