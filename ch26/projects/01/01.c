#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // a) I don't see any patterns
    for (int i = 0; i < 1000; ++i)
        printf("%d", rand() & 0b1);

    printf("\n\n");

    // b) for range [0,N)
    int N = 1;
    for (int i = 0; i < 1000; ++i)
        printf("%d", rand()/((RAND_MAX/(N+1))-1));
}