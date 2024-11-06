#include <stdio.h>

int main(void)
{
	int days_in_month, starting_day;

	printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &starting_day);

    for (int i = 1; i < starting_day; ++i)
        printf("   ");
    
    for (int i = 1; i <= days_in_month; ++i) {
        printf("%2d ", i);
        if ((i + starting_day - 1 ) % 7 == 0)
            printf("\n");
    }
}