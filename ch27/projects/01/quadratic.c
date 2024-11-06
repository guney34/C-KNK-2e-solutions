#include <complex.h>
#include <stdio.h>

//Note: msvc doesn't properly implement complex types, so compile with gcc/UCRT64

int main(void)
{
    double a, b, c;
	
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter c: ");
	scanf("%lf", &c);
	
	double discriminant = b*b - 4*a*c;
    double complex discriminant_sqrt = csqrt(discriminant);
    double complex root1 = (-b + discriminant_sqrt) / (2 * a);
    double complex root2 = (-b - discriminant_sqrt) / (2 * a);
	
	if (discriminant < 0) {
		printf("root1 = %g %c %gi\n", creal(root1),
               cimag(root1) < 0 ? '-' : '+',
			   cimag(root1) < 0 ? -cimag(root1) : cimag(root1));
		printf("root2 = %g %c %gi\n", creal(root2),
			   cimag(root2) < 0 ? '-' : '+',
			   cimag(root2) < 0 ? -cimag(root2) : cimag(root2));
	} else {
		printf("root1 = %g\n", creal(root1));
		printf("root2 = %g\n", creal(root2));
	}

    return 0;
}
