#include <stdio.h>

int power(int x, int n)
{
    if (n % 2)
        return n == 0 ? 1 : x * power(x, n - 1);
    else
        return n == 0 ? 1 : power(x, n/2) * power(x, n/2);
}

int main(void)
{
    int x, n;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d^%d = %d", x, n, power(x, n));
}