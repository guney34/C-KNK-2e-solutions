#include <stdio.h>

int main(void)
    {
	int h, m;

    printf("Enter a 24-hour time: ");
    scanf("%2d :%2d", &h, &m);
    printf("Equivalent 12-hour time: ");

    if (h == 24)
        h -= 24;

    if (h > 12)
        printf("%.2d:%.2d", h - 12, m);
    else
        printf("%.2d:%.2d", h, m);

    if (h >= 12)
        printf(" PM");
    else
        printf(" AM");
}