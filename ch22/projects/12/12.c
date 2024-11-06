#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[])
{
	if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

	FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");

	char line_str[MAX_LINE_LEN+1];
	int number, day, month, year;
	float price;

	while (fgets(line_str, sizeof(line_str), fp) != NULL) {
		sscanf(line_str, "%d,%f,%d/%d/%d", &number, &price, &day, &month, &year);
		printf("%-8d\t$%8.2f\t%.2d/%.2d/%.4d\n", number, price, day, month, year);
	}

	fclose(fp);
}