#include <stdio.h>

#define MAX 15

int main(void)
{
    char number[MAX] = {0};

    printf("Enter a phone number: ");
    for (int i = 0; i < MAX; ++i) {
        char ch;
        if ((ch = (char)getchar()) != '\n')
            number[i] = ch;
        else
            break;
    }
    
    printf("In numeric form: ");
    for (int i = 0; i < MAX; ++i) {
        switch (number[i]) {
            case 0: goto end;
            case 'A': case 'B': case 'C': putchar('2'); break;
            case 'D': case 'E': case 'F': putchar('3'); break;
            case 'G': case 'H': case 'I': putchar('4'); break;
            case 'J': case 'K': case 'L': putchar('5'); break;
            case 'M': case 'N': case 'O': putchar('6'); break;
            case 'P': case 'R': case 'S': putchar('7'); break;
            case 'T': case 'U': case 'V': putchar('8'); break;
            case 'W': case 'X': case 'Y': putchar('9'); break;
            default: putchar(number[i]); break;
        }
    }
    end:
}