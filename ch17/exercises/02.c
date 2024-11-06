char *duplicate(const char *str)
{
    char *new_str = malloc(sizeof(char) * strlen(str) + 1);
    if (new_str == NULL)
        return NULL;
    strcpy(new_str, str);
    return new_str; 
}