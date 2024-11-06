#include <stdio.h>

int main(void)
{
    float result;
    float number;
    int ch;

    printf("Enter an expression: ");
    scanf("%f", &result);

    while ((ch = getchar()) != '\n') {
        switch(ch) {
            case ' ': break;
            case '+':
                scanf("%f", &number);
                result += number;
                break;
            case '-':
                scanf("%f", &number);
                result -= number;
                break;
            case '*':
                scanf("%f", &number);
                result *= number;
                break;
            case '/':
                scanf("%f", &number);
                result /= number;
                break;
            default:
            return 0;
        }
    }
    printf("Value of expression: %f\n", result);
}