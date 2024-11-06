#include <stdio.h>

int main(void)
{
    char *month_name[12] = { "January", "February", "March", "April", "May", "June", "July",
                             "August", "September", "October", "November", "December" };

    int day, month, year;

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d /%d / %d", &day, &month, &year);
    printf("You entered the date %s %d, %d", month_name[month - 1], day, year);
}