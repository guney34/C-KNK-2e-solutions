void remove_filename(char *url)
{
    while (*url++)
        ;
    while (*(--url) != '/')
        ;
    *url = 0;
}