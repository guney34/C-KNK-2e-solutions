int num_digits(int n)
{
    int digits = 1;
    while (n /= 10)
        ++digits;
    return digits;
}