//a)
char *my_strdup(const char *s)
{
    char *copy = malloc(strlen(s)+1);
    if (copy == NULL)
        return NULL;
        
    strcpy(copy, s);
    return copy;
}

//b)
int my_stricmp(const char *s1, const char *s2)
{
    for (; tolower(*s1) == tolower(*s2); ++s1, ++s2)
        if (*s1 == '\0')
            return 0;

    return (*s1 > *s2) - (*s1 < *s2);
}

//c)
char *my_strlwr(char *s)
{
    for (char *p = s; *p; ++p)
        *p = tolower(*p);
    return s;
}

//d)
char *my_strrev(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len/2; ++i) {
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
    return s;
}

//e)
char *my_strset(char *s, int ch)
{
    memset(s, ch, strlen(s));
    return s;
}