#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MSG_LEN 256

bool is_palindrome(const char *message)
{
    const char *start = message;
    const char *last = message + strlen(message) - 1;

    while (last - start > 1) {
        if (!isalpha(*last)) {
            --last;
            continue;
        }
        if (!isalpha(*start)) {
            ++start;
            continue;
        }

        if (toupper(*start) != toupper(*last))
            return false;
        ++start;
        --last;
    }
    return true;
}

int main(void)
{
    printf("Enter a message: ");
    char msg[MSG_LEN+1];
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';

    if (is_palindrome(msg))
        printf("Palindrome");
    else
        printf("Not a palindrome");
}