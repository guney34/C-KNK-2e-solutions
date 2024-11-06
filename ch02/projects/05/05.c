#include <stdio.h>

int main(void)
{
	float x;
	printf("Enter a value for x: ");
	scanf("%f", &x);
	printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %.2f",
		3.0f*x*x*x*x*x + 2.0f*x*x*x*x - 5.0f*x*x*x - x*x + 7.0f*x - 6.0f);
}