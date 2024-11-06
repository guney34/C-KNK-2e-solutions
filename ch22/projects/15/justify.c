#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: %s source dest\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("%s can't be opened\n", argv[2]);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1, fp_in);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(fp_out);
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line(fp_out);
            clear_line();
        }
        add_word(word);
    }

    fclose(fp_in);
    fclose(fp_out);
}
