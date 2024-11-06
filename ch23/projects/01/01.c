#include <stdio.h>
#include <math.h>

int main(void)
{
    double a,b,c;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter a: ");
    scanf("%lf", &c);

    if (fma(b, b, -4.0*a*c) < 0.0) {
        printf("The roots are complex\n");
        return 0;
    }

    double x1 = (-b + sqrt(fma(b, b, -4.0*a*c)))/2;
    double x2 = (-b - sqrt(fma(b, b, -4.0*a*c)))/2;

    printf("x1 = %f\nx2 = %f\n", x1, x2);
}