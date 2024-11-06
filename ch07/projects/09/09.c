#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int h, m;
    char ch1, ch2;
    printf("Enter a 12-hour time: ");
    scanf("%2d :%2d %c%c", &h, &m, &ch1, &ch2);

    if (toupper(ch1) == 'A' && (toupper(ch2) == 'M' || toupper(ch2) == '\n')) {
        if (h == 12)
            h = 0;
    } else if (toupper(ch1) == 'P' && (toupper(ch2) == 'M' || toupper(ch2) == '\n')) {
        if (h != 12)
            h += 12;
    } else
        return 0;
    
    printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);
}