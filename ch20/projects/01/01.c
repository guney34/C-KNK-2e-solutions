#include <stdio.h>

union {
    float cfloat;

    struct {
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
    } IEEE_float32;
} f;

int main(void)
{
    f.IEEE_float32.sign = 1;
    f.IEEE_float32.exponent = 128;
    f.IEEE_float32.fraction = 0;

    printf("%f", f.cfloat);
}