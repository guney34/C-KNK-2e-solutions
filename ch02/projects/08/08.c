#include <stdio.h>

int main(void)
{
	float loan;
	printf("Enter amount of loan: ");
	scanf("%f", &loan);

	float interest_rate;
	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	float monthly_payment;
	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	loan -= monthly_payment;
	loan *= 1.0f + ((interest_rate / 100.0f) / 12.0f);
	printf("Balance remaining after first payment: %.2f\n", loan);
	loan -= monthly_payment;
	loan *= 1.0f + ((interest_rate / 100.0f) / 12.0f);
	printf("Balance remaining after second payment: %.2f\n", loan);
	loan -= monthly_payment;
	loan *= 1.0f + ((interest_rate / 100.0f) / 12.0f);
	printf("Balance remaining after third payment: %.2f\n", loan);
}