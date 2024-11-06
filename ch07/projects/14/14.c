#include <stdio.h>
#include <math.h>

int main(void)
{
    double n;
    double guess = 1;

    printf("Enter a positive number: ");
    scanf("%lf", &n);

    while (fabs(0.5*((n / guess) +  guess) - guess) >= 0.00001) {
        guess = 0.5*((n / guess) +  guess);
    }
}