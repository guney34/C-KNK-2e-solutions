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

    int num_payments;
    printf("Enter number of payments: ");
	scanf("%d", &num_payments);

    for (int i = 1; i <= num_payments; ++i) {
	    loan -= monthly_payment;
	    loan *= 1.0f + ((interest_rate / 100.0f) / 12.0f);
	    printf("Balance remaining after payment %d: %.2f\n", i, loan);
    }
}