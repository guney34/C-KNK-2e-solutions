char *vstrcat(const char *first, ...)
{
    va_list ap;
    size_t size = 1+strlen(first);

    va_start(ap, format);
    for (char *p = va_arg(ap, char *); p; p = va_arg(ap, char *))
        size += strlen(p);

    char *str = malloc(size);
    if (str == NULL)
        return NULL;
    str[0] = '\0';

    strcat(str, first);

    va_start(ap, format);
    for (char *p = va_arg(ap, char *); p; p = va_arg(ap, char *))
        strcat(str, p);

    va_end(ap);
    return str;
}