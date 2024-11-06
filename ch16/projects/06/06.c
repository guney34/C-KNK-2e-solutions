#include <stdio.h>

struct date {
    int day, month, year;
};

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
        return 0;
    if ((d1.year < d2.year) ||
        (d1.year == d2.year && d1.month < d2.month) ||
        (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day))
        return -1;
    return 1;
}

int main(void)
{
    struct date d1;
    struct date d2;

    printf("Enter first date (dd/mm/yy): ");
    scanf("%d /%d /%d", &d1.day, &d1.month, &d1.year);
    printf("Enter second date (dd/mm/yy): ");
    scanf("%d /%d /%d", &d2.day, &d2.month, &d2.year);

    switch (compare_dates(d1, d2)) {
        case 0:
            printf("%d/%d/%.2d is equal to %d/%d/%.2d",
                   d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
            break;
        case -1:
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d",
                   d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
            break;
        case 1:
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d",
                   d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
            break;
    }
}