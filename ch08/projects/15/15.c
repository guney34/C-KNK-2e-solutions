#include <stdio.h>

#define SIZE 80

int main(void)
{
    char msg[SIZE] = {0};
    char ch;
    int shift;
    int len = 0;

    printf("Enter message to be encrypted: ");

    for (int i = 0; i < SIZE; ++i) {
        ch = (char)getchar();
        if (ch == '\n')
            break;
        msg[i] = ch;
        ++len;
    }
    
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    printf("Encrypted message: ");

    for (int i = 0; i < len; ++i) {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            putchar(((msg[i] - 'A') + shift) % 26 + 'A');
        else if (msg[i] >= 'a' && msg[i] <= 'z')
            putchar(((msg[i] - 'a') + shift) % 26 + 'a');
        else 
            putchar(msg[i]);
    }
}