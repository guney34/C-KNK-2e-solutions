#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm t;
    int n;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d /%d /%d", &t.tm_mday, &t.tm_mon, &t.tm_year);
    t.tm_year -= 1900;
    t.tm_mon -= 1;

    printf("Enter number of days later: ");
    scanf("%d", &n);

    
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_isdst = -1;
    t.tm_mday += n;

    mktime(&t);
    printf("New Date: %.2d/%.2d/%.4d\n", t.tm_mday, t.tm_mon+1, t.tm_year+1900);

}