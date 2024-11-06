#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
	int numerator, denominator, reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);

    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
    printf("In lowest terms: %d/%d", reduced_numerator, reduced_denominator);
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    *reduced_numerator = numerator;
    *reduced_denominator = denominator;

    while (numerator != 0) {
        int remainder = denominator % numerator;
        denominator = numerator;
        numerator = remainder;
    }
    *reduced_numerator /= denominator;
    *reduced_denominator /= denominator;
}