#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    while(1) {
        int digit_seen[10] = {0};
        int digit;
        long n;

        printf("Enter a number: ");
        scanf("%ld", &n);
        if (n <= 0)
            return 0;

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
        printf("\n");
    }
}