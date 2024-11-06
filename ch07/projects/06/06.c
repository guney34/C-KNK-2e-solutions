#include <stdio.h>

int main(void)
{
    printf("Size of int: %d-bit\n",         8 * (int)sizeof(int));
    printf("Size of short: %d-bit\n",       8 * (int)sizeof(short));
    printf("Size of long: %d-bit\n",        8 * (int)sizeof(long));
    printf("Size of float: %d-bit\n",       8 * (int)sizeof(float));
    printf("Size of double: %d-bit\n",      8 * (int)sizeof(double));
    printf("Size of long double: %d-bit\n", 8 * (int)sizeof(long double));
}