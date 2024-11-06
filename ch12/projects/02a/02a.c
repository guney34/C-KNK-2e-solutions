#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 256

int main(void)
{
    char ch;
    char msg[SIZE] = {0};
    size_t len = 0;

    printf("Enter a message: ");
    while ((ch = (char)getchar()) != '\n' && len < SIZE)
        if(isalpha(ch))
            msg[len++] = ch;

    bool isPalindrome = true;
    for (size_t i = 0; i < len/2; ++i) {
        if (toupper(msg[i]) != toupper(msg[len-i-1])) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");
}