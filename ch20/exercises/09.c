//a)
int count_ones(unsigned char ch)
{
    int count = 0;
    while (ch) {
        if (ch & 0x1u)
            ++count;
        ch >>= 1;
    }
    return count;
}
//b)
int count_ones2(unsigned char ch)
{
    if (ch == 0x0u)
        return 0;
    return count_ones2(ch>>1) + (ch & 0x1u);
}