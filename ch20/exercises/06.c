#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
    return (i<<8) | (i>>8);
}

int main(void)
{
    printf("Enter a hexadecimal number (up to four digits): ");
    
    unsigned short number;
    scanf("%hx", &number);
    printf("Number with bytes swapped: %hx", swap_bytes(number));
}