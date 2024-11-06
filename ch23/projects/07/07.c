#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int ch;
    int last_ch = '\0';
    int count = 0;

    for (; (ch = getchar()) != EOF; last_ch = ch)
        if(isspace(ch) && strchr(".?!", last_ch))
            ++count;

    if (strchr(".?!", last_ch) && !ferror(stdin))
        ++count;

    printf("Number of sentences: %d\n", count);
}