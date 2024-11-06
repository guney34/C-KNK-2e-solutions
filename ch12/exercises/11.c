int *find_largest(int *a, int n)
{
    int *max = a;
    for (int *p = a + 1; p < a + n; ++p)
        if (*p > *max)
            max = p;
    return max;
}