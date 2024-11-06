#include <stdio.h>

int main(void)
{
    float epsilon;
	printf("Enter ε: ");
    scanf("%f", &epsilon);

    float e = 0.0f;
    float term = 1.0f;
    for (int i = 1, factorial = 1; term >= epsilon; ++i) {           
        e += term; 
        term = 1.0f/(float)(factorial *= i);
    }
    printf("e ≈ %f", e);
}