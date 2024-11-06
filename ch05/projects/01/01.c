#include <stdio.h>

int main(void)
{
	int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The number %d has ", n);

    if (n <= 9)
        printf("1 digit");
    else if (n <= 99)
        printf("2 digits");
    else if (n <= 999)
        printf("3 digits");
    else
        printf("4+ digits");
}