#include <stdio.h>

int main(void)
{
    int day, month, year;

    printf("Enter a date (dd/mm/yy): ");
    scanf("%d /%d /%d", &day, &month, &year);
    if (!day && !month && !year)
        return 0;

    int e_day = day; 
    int e_month = month; 
    int e_year = year;

    while (day || month || year) {
        if (year < e_year || (year == e_year && month < e_month) ||
            (year == e_year && month == e_month && day < e_day)) {
                
            e_day = day; 
            e_month = month; 
            e_year = year;
        }
        printf("Enter a date (dd/mm/yy): ");
        scanf("%d /%d /%d", &day, &month, &year);
    }
    printf("%d/%d/%.2d is the earliest date", e_day, e_month, e_year);
}