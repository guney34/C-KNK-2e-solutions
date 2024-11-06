#include <stdio.h>
#include <ctype.h>

#define MAX_MSG_SIZE 256

int main(void)
{
    int msg[MAX_MSG_SIZE] = {0};
    int msg_size = 0;
    int ch;

    printf("Enter a message: ");
    for (int i = 0; i < MAX_MSG_SIZE; ++i) {
        if ((ch = getchar()) == '\n')
            break;
        msg[i] = ch;
        msg_size += 1;
    }
    printf("In B1FF-speak: ");
    for (int i = 0; i < msg_size; ++i) {
        switch(toupper(msg[i])) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break;
            default: putchar(toupper(msg[i])); break;
        }
    }
    printf("!!!!!!!!!!");
}