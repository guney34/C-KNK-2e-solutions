#include <stdio.h>

int main(void)
{
	int number;
	printf("Enter item number: ");
	scanf("%d", &number);

	float price;
	printf("Enter unit price: ");
	scanf("%f", &price);

	int day, month, year;
	printf("Enter a purchase date (dd/mm/yyyy): ");
	scanf("%d /%d /%d", &day, &month, &year);
	printf("\n");

	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");
	printf("%-8d\t$%8.2f\t%.2d/%.2d/%.4d\n", number, price, day, month, year);
}