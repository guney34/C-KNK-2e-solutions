void capitalilse(char str[], int n)
{
    char *p = str;
    while(*p) {
        *p = toupper(*p);
        ++p;
    }
}