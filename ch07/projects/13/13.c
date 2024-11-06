#include <stdio.h>

int main(void)
{
    int ch;
    int words = 0;
    int letters = 0;

    printf("Enter an sentence: ");
    
    do {
        while ((ch = getchar()) == ' ') { }; //skip empty spaces
        do {
            if (ch == '\n')
                break;
            ++letters;
        } while ((ch = getchar()) != ' ');
        ++words;
    } while (ch  != '\n');

    printf("Average word length: %.1f\n", (float)letters / (float)words);
}