void get_extension(const char *file_name, char *extension)
{
    file_name += strlen(file_name);
    while (*(--file_name) != '.')
        ;
    strcpy(extension, file_name + 1);
}