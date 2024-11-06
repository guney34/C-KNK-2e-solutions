#include <stdio.h>

int main(void)
{
    int number;
    char *ones[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                       "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen" };
    char *tens[10] = { "zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if ((number > 99) || (number < 0)) {
        printf("ERROR: Number out of range.");
        return 0;
    }

    printf("You entered the number ");

    if (number / 10 == 1) {
        printf("%s", ones[number]);
    } else {
        if (number / 10)
            printf("%s", tens[number / 10]);

        if ((number >= 20) && (number % 10 != 0))
            printf("-");
        
        if (number % 10 || number == 0)
            printf("%s", ones[number % 10]);
    }
    printf(".");
}