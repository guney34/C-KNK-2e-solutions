unsigned int rotate_left(unsigned int i, int n)
{
    return (i<<n) | (i>>(32-n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return (i>>n) | (i<<(32-n));
}