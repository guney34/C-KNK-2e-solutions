#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm t1, t2;

    printf("Enter first date (dd/mm/yyyy): ");
    scanf("%d /%d /%d", &t1.tm_mday, &t1.tm_mon, &t1.tm_year);
    t1.tm_year -= 1900;
    t1.tm_mon -= 1;
    t1.tm_sec = 0;
    t1.tm_min = 0;
    t1.tm_hour = 0;
    t1.tm_isdst = -1;

    printf("Enter second date (dd/mm/yyyy): ");
    scanf("%d /%d /%d", &t2.tm_mday, &t2.tm_mon, &t2.tm_year);
    t2.tm_year -= 1900;
    t2.tm_mon -= 1;
    t2.tm_sec = 0;
    t2.tm_min = 0;
    t2.tm_hour = 0;
    t2.tm_isdst = -1;

    printf("Difference: %.2f days\n", difftime(mktime(&t2), mktime(&t1)) / (3600*24));
}