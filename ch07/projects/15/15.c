#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    long double factorial = 1.0L;
    for (int i = 1; i <= n; ++i) {
        factorial *= (long double)i;
    }
    printf("Factorial of %d: %Lf", n, factorial);
}

// a) 7
// b) 12
// c) 12
// d) 20
// e) 13
// f) 22
// g) 22