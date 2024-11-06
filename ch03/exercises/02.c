#include <stdio.h>

int main()
{
    float x = 12.34f;

    printf("%-8.1e", x);    //a)

    printf("\n");

    printf("%10.6e", x);    //b)
    
    printf("\n");

    printf("%-8.3f", x);    //c)

    printf("\n");

    printf("%6.0f", x);     //d)
}