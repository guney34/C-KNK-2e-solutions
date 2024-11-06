#include <stdio.h>

int main(void)
{
    int n;

	printf("Enter number of terms: ");
    scanf("%d", &n);

    float e = 1.0f;
    for (int i = 1, factorial = 1; i <= n-1; ++i) {           
        e += 1.0f/(float)(factorial *= i); 
    }
    printf("e ≈ %f", e);
}