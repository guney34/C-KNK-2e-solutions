#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
    struct tm *tp = localtime(&t);

    char str[50];

    strftime(str, sizeof(str), "%A, %B %d, %Y %I:%M", tp);
    printf("%s%c\n", str, tp->tm_hour < 12 ? 'a' : 'p');

    strftime(str, sizeof(str), "%a, %d %B %y %R", tp);
    printf("%s\n", str);

    strftime(str, sizeof(str), "%D %r", tp);
    printf("%s\n", str);
}