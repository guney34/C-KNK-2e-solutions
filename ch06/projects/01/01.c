#include <stdio.h>

int main(void)
{
	float n;
    float max = 0.0f;

    printf("Enter a number: ");
    scanf("%f", &n);
    if (n <= 0)
        return 0;
    if (n > max)
        max = n;

    while (n > 0) {
        printf("Enter a number: ");
        scanf("%f", &n);
        if (n > max)
            max = n;
    }
    printf("The largest number entered was %f", max);
}