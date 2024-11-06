#include <stdio.h>

int main(void)
{
	float x;
	printf("Enter a value for x: ");
	scanf("%f", &x);
	printf("((((3x + 2)x - 5)x - 1)x + 7)x - 6 = %.2f",
		((((3.0f*x + 2.0f)*x - 5.0f)*x - 1.0f)*x + 7.0f)*x - 6.0f);
}