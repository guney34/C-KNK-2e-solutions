#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        ++digit_seen[digit];
        n /= 10;
    }
    printf("Digit:\t\t");
    for (int digit = 0; digit < 10; ++digit) {
        printf("%3d", digit);
    }
    printf("\nOccurrences:\t");
    for (int digit = 0; digit < 10; ++digit) {
        printf("%3d", digit_seen[digit]);
    }
}