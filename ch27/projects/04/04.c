#include <stdio.h>
#define _USE_MATH_DEFINES
#include <tgmath.h>


//Note: msvc doesn't properly implement complex types, so compile with gcc/UCRT64

int main(void)
{
    int n;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	for (int k = 0; k <= n-1; ++k) {
		double complex z = exp((2*M_PI*I*k)/(double)n);
		printf("z = %g %c %gi\n", creal(z),
               cimag(z) < 0 ? '-' : '+',
		       cimag(z) < 0 ? -cimag(z) : cimag(z));
	}
}
