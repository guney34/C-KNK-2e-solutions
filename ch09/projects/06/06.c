#include <stdio.h>

double polynomial(double x)
{
    return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x +7*x -6;
}

int main(void)
{
    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("3x^5 + 2^4x - 5x^3 - x^2 + 7x - 6 = %.2lf", polynomial(x));
}