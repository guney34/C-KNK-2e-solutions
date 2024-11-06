#include <stdio.h>

int main(void)
{
    int a, b, c, d, min, max, min2, max2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (a >= b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    if (c >= d) {
        max2 = c;
        min2 = d;
    } else {
        max2 = d;
        min2 = c;
    }

    if (max2 > max)
        max = max2;

    if (min2 < min)
        min = min2;

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
}