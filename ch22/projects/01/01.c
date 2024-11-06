#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc < 2) {
        printf("usage: %s filename filename2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            continue;
        }
        printf("%s can be opened\n", argv[i]);
        fclose(fp);
    }
}
