#include <stdio.h>

int main(void)
{
    int i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        printf("%10d%10d\n", i, i * i);
}
// fails if input is 46341, as 46341 squared is just above the signed 32-bit integer limit
// sqrt(2^31) = 46340.9500...
// int is 32-bit on 64-bit windows