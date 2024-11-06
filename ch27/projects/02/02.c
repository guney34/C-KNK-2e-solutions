#include <complex.h>
#include <stdio.h>

//Note: msvc doesn't properly implement complex types, so compile with gcc/UCRT64

int main(void)
{
    double a, b;
	
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	
	double complex z = a + b*I;
	
	printf("Phase angle: %f rad\n", carg(z)); 
	printf("Modulus: %f\n", cabs(z)); 
}
