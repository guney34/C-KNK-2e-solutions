int digit(int n, int k)
{
    for (int i = 1; i < k; ++i)
        n /= 10;
    return n % 10;
}