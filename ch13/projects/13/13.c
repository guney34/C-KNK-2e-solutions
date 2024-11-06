#include <stdio.h>
#include <string.h>

#define MSG_LEN 80

void encrypt(char *message, int shift)
{
    while (*message) {
        if (*message >= 'A' && *message <= 'Z')
            *message = (*message - 'A' + shift) % 26 + 'A';
        else if (*message >= 'a' && *message <= 'z')
            *message = (*message - 'a' + shift) % 26 + 'a';
        ++message;
    }
}

int main(void)
{
    char msg[MSG_LEN+1];
    int shift;

    printf("Enter message to be encrypted: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(msg, shift);
    printf("Encrypted message: ");
    puts(msg);
}