#include <stdio.h>

int main(void)
{
    float knots;

    printf("Enter wind speed (knots): ");
    scanf("%f", &knots);

    printf("Description: ");
    if      (knots < 1)  printf("Calm");
    else if (knots < 3)  printf("Light air");
    else if (knots < 27) printf("Breeze");
    else if (knots < 47) printf("Gale");
    else if (knots < 63) printf("Storm");
    else                 printf("Hurricane");
}