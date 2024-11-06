#include <complex.h>
#include <stdio.h>
#include <math.h>

//Note: msvc doesn't properly implement complex types, so compile with gcc/UCRT64

int main(void)
{
    double r, theta;
	
	printf("Enter modulus: ");
	scanf("%lf", &r);
	printf("Enter phase angle (in radians): ");
	scanf("%lf", &theta);
	
	double complex z = r*cos(theta) + r*sin(theta)*I;
	
	printf("z = %g %c %gi\n", creal(z),
           cimag(z) < 0 ? '-' : '+',
		   cimag(z) < 0 ? -cimag(z) : cimag(z));

}
