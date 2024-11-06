#include <stdio.h>
#include <string.h>

#define MSG_LEN 256

void reverse(char *message)
{
    char *start = message;
    char *last = message + strlen(message) - 1;

    while (last - start > 1) {
        char temp = *start;
        *start = *last;
        *last = temp;

        ++start;
        --last;
    }
}

int main(void)
{
    printf("Enter a message: ");
    char msg[MSG_LEN + 1];
    gets(msg);

    reverse(msg);
    printf("Reversal is: ");
    puts(msg);
}