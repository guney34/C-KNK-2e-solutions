#include <stdio.h>

int main(void)
{
	int day, month, year;

	printf("Enter a date (dd/mm/yyyy): ");
	scanf("%d /%d /%d", &day, &month, &year);

	printf("You entered the date %.4d%.2d%.2d", year, month, day);
}