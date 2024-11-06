bool is_identifier(char *str)
{
    if (!isalpha(*str) && *str != '_')
        return false;

    while (*(++str))
        if (!isalnum(*str) && *str != '_')
            return false;

    return true;
}