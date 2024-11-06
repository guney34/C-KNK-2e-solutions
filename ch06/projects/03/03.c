#include <stdio.h>

int main(void)
{
	int a, b;

    printf("Enter a fraction: ");
    scanf("%d /%d", &a, &b);

    int remainder;
    int n = a;
    int m = b;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    printf("In lowest terms: %d/%d", a/m, b/m);
}