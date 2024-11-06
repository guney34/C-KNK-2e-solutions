// a)
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) == ' ')
        ;
    while (ch != '\n') {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
// b)
int read_line(char str[], int n)
{
    int ch, i = 0;
    while (!isspace(ch = getchar()))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
// c)
int read_line(char str[], int n)
{
    int ch, i = 0;
    do {
        ch = getchar();
        if (i < n)
            str[i++] = ch;
    } while (ch != '\n');
    str[i] = '\0';
    return i;
}
// d)
int read_line(char str[], int n)
{
    int ch, i = 0;
    while (i < n - 1 && (ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}