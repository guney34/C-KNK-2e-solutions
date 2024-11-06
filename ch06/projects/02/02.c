#include <stdio.h>

int main(void)
{
	int n, m;

    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    int remainder;
    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    printf("Greatest common divisor: %d", m);
}