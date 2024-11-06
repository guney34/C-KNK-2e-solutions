char *my_fgets(char * restrict s, int n, FILE * restrict stream)
{
    int i = 0;
    char ch;

    while ((ch = (char)fgetc(stream)) != EOF && i < n-1) {
        s[i++] = ch;
        if (ch == '\n')
            break;
    }
    s[i] = '\0';

    if (i == 0 || ferror(stream))
        return NULL;
    return s;
}

int my_fputs(const char * restrict s, FILE * restrict stream)
{
    while (*s != '\0') {
        if (putc(*s, stream) == EOF)
            return EOF;
        ++s;
    }
    return 0;
}