#include <stdio.h>
#include <math.h>

int main(void)
{
    double interest, deposit, num_years;

    printf("Enter deposit amount/$: ");
    scanf("%lf", &deposit);

    printf("Enter annual interest rate/%%: ");
    scanf("%lf", &interest);
    interest /= 100.0;

    printf("Enter number of years: ");
    scanf("%lf", &num_years);

    printf("Result: %lf", deposit * exp(interest * num_years));
}