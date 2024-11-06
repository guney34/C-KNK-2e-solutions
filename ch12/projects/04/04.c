#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 256

int main(void)
{
    char ch;
    char msg[SIZE] = {0};
    char *pos = msg;

    printf("Enter a message: ");
    while ((ch = (char)getchar()) != '\n' && pos < msg+SIZE)
        if(isalpha(ch))
            *pos++ = ch;

    bool isPalindrome = true;
    for (char *p = msg; p < msg + (pos - msg)/2; ++p) {
        if (toupper(*p) != toupper(*(msg + (pos-p-1)))) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");
}