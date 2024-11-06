#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("usage: %s input1 input2 output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *in_fp1 = fopen(argv[1], "rb");
    if (in_fp1 == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *in_fp2 = fopen(argv[2], "rb");
    if (in_fp2 == NULL) {
        printf("%s can't be opened\n", argv[2]);
        fclose(in_fp1);
        exit(EXIT_FAILURE);
    }

    FILE *out_fp = fopen(argv[3], "wb");
    if (out_fp == NULL) {
        printf("%s can't be opened\n", argv[3]);
        fclose(in_fp1);
        fclose(in_fp2);
        exit(EXIT_FAILURE);
    }

    struct part part1;
    struct part part2;
    size_t n1 = fread(&part1, sizeof(struct part), 1, in_fp1);
    size_t n2 = fread(&part2, sizeof(struct part), 1, in_fp2);

    while (n1 == 1 & n2 == 1) {
        if (part1.number < part2.number) {
            fwrite(&part1, sizeof(struct part), 1, out_fp);
            n1 =fread(&part1, sizeof(struct part), 1, in_fp1);
        } else if (part1.number > part2.number) {
            fwrite(&part2, sizeof(struct part), 1, out_fp);
            n2 = fread(&part2, sizeof(struct part), 1, in_fp2);
        } else {
            if (strcmp(part1.name, part2.name))
                printf("Part %d names does not match for both files\n", part1.number);

            part1.on_hand += part2.on_hand;
            fwrite(&part1, sizeof(struct part), 1, out_fp);
            n1 = fread(&part1, sizeof(struct part), 1, in_fp1);
            n2 = fread(&part2, sizeof(struct part), 1, in_fp2);
        }
    }

    while (n1 == 1) {
        fwrite(&part1, sizeof(struct part), 1, out_fp);
        n1 =fread(&part1, sizeof(struct part), 1, in_fp1);
    }

    while (n2 == 1) {
        fwrite(&part2, sizeof(struct part), 1, out_fp);
        n2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    }

    fclose(in_fp1);
    fclose(in_fp2);
    fclose(out_fp);
}