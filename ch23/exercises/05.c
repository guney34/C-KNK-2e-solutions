long int hexstol(char *str)
{   
    for (char *p = str; *p; ++p)
        if (!isxdigit(*p))
            return -1;
    return strtol(str, NULL, 16);
}