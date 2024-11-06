bool test_extension(const char *file_name,const char *extension)
{
    while (*file_name++ != '.')
        ;
    while (*extension && *file_name)
        if (toupper(*file_name++) != toupper(*extension++))
            return false;
    return true;
}